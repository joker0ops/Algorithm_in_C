#include<iostream>
using namespace std;
#define ElemType int

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    // 头结点的prior永远指向NULL
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 双链表的后插操作，在p后插入结点s
// 按位序插入操作可找到待插入位置的前一个结点再调用此后插函数
// 前插操作可以根据前驱结点找到待插入位置的前一个结点再调用后插函数
bool InsertNextDNode(DNode *p, DNode *s){
    if(p == NULL || s == NULL)
        return false;
    s->next = p->next;
    // 如果p结点是最后一个结点，则不需要设置p->next的前驱结点
    if(p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p结点的后继结点
bool DeleteNextDNode(DNode *p){
    if(p==NULL)
        return false;
    DNode *q = p->next;
    if(q==NULL)
        return false;
    p->next = q->next;
    // 如果q没有后继结点则不需要设置其后继结点的前驱结点
    if(q->next!=NULL)
        q->next->prior = p;
    free(q);
    return true;
}

void DestroyList(DLinkList &L){
    // 循环释放各个数据结点
    while(L->next!=NULL){
        DeleteNextDNode(L);
        // L=L->next;
        // 这里不需要移位就可以依次删除！！！想想删除L的后继结点后链表的情况
    }
    free(L);
    L=NULL;
}

bool Empty(DLinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

int main(){
    DLinkList L;
    InitDLinkList(L);
    return 0;
}