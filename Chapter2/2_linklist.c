#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 定义链表的结点类型——数据区+地址区
typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;
// 定义链表类型，以便于为指定链表附加length属性，便于对链表进行管理
typedef struct LinkList{
    /*  这里不是定义一个ListNode型指针，而是定义了一个ListNode类型的元素（虚拟头节点）
        使用head的地址域来指向链表的第一个节点而不是让head作为第一个节点
        [head|val|&p1] -> [p1|val|&p2] -> [p2|val|p3] -> [p3|val|NULL] -> NULL
        由于插入和删除操作都要找到对应节点的前一个节点，因此对于上述结构，若对第0位进行操作无需移动，对第一位进行操作只需移动一位，以此类推
    */
    ListNode head;
    // 链表的元素个数
    int length;
}LinkList;

// 因为有两个结构（链表结构和链表节点结构），因此要对两个结构分别初始化
// 初始化链表节点，在插入新节点时调用
ListNode *init_listnode(int val){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));
    p->data = val;
    return p;
}

// 初始化链表
LinkList *init_linklist(){
    LinkList *l=(LinkList*)malloc(sizeof(LinkList));
    // 链表的第一个节点为空
    l->head.next = NULL;
    l->length=0;
    return l;
}

// 释放节点空间，在释放链表空间时调用
void clear_listnode(ListNode *node){
    // 若该节点为空，则直接返回
    if (node == NULL) return ;
    // 释放该节点
    free(node);
    return ;
}

// 释放链表空间
void clear_linklist(LinkList *l){
    // 若该链表为空，释放该链表
    if (l == NULL) return;
    // 否则，从头节点开始遍历每一个节点并释放节点空间
    ListNode *p = l->head.next, *q;
    while (p){
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(l);
    return;
}

// 指定位置插入节点
int insert(LinkList *l, int ind, int val){
    // 若链表为空，插入失败
    if (l == NULL) return 0;
    // 若插入位置在第一个元素之前或在最后一个元素之后两位，插入失败
    if (ind < 0 || ind > l->length) return 0;
    // 取得head的地址以访问链表并初始化要插入的新节点
    ListNode *p = &(l->head), *node = init_listnode(val);
    while(ind--){
        p=p->next;
    }
    // p指向待插入位置的前一个节点
    node->next = p->next;
    p->next = node;
    // 链表长度加一
    l->length++;
    return 1;
}

int erase(LinkList *l, int ind){
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    // p指向待删除节点的前一个节点
    ListNode *p = &(l->head), *q;
    while (ind--){
        p = p->next;
    }
    q = p->next->next;
    // 直接释放p->next节点
    clear_listnode(p->next);
    p->next = q;
    // 链表长度减一
    l->length--;
    return 1;
}

// 输出整个链表
void output(LinkList *l){
    printf("LinkList(%d): ", l->length);
    // p非空(p!=NULL)也可以直接写成p
    for (ListNode *p = l->head.next; p!=NULL; p = p->next){
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
    return ;
}

#define MAX_OP 30
int main(){
    srand(time(0));
    LinkList *l = init_linklist();
    for(int i = 0; i < MAX_OP; i++){
        int op = rand() % 3;
        // 测试用位置在0到l->length之间
        int ind = rand() % (l->length + 1);
        int val = rand() % 100;
        switch (op)
        {
            // 当哦op为0或1时均执行插入操作，实现66%的概率测试插入操作
            case 0:
            case 1: {
                printf("insert %d at %d to LinkList = %d\n",
                 val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("erase item at %d from LinkList = %d\n",
                ind, erase(l, ind));
            } break;
        }
        output(l);
        printf("\n");
    }
    clear_linklist(l);
    return 0;
}