#include<iostream>
using namespace std;
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// 初始化不带头结点的单链表
bool InitList(LinkList &L){
    // 将L指向NULL表示空表，同时可以防止脏数据
    L = NULL;
    return true;
}

// 初始化带头结点的单链表，更方便操作
bool InitList2(LinkList &L){
    // 申请一个LNode型的空间存放头节点
    L = (LNode*)malloc(sizeof(LNode));
    // 内存不足，分配失败
    if(L == NULL)
        return false;
    // 注意头节点不存储数据，只是为了方便操作使用
    L->next = NULL;
    return true;
}

// 带头节点的按位序插入
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    // 指针p始终指向当前扫描到的节点
    LNode *p;
    // 标识当前p指向的是第几号节点，当前指向头节点为0号
    int j=0;
    // L指向头结点，头结点是第0个结点（不存放数据）
    p = L;
    while(p!=NULL&&j<i-1){
        // 循环找到第i-1个结点
        /*
        注意：
        由于单链表只能向后连接，因此在插入和删除操作中，为找到指定位置，
        必须找到该位置的前一个结点
        */
        p=p->next;
        j++;
    }
    // 这里的判空操作可防止将结点误操作插入到空区域
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 不带头结点的按位序插入
bool ListInsert2(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    // 专门整理头结点的操作
    if(i==1){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        // 此时L==NULL
        s->next = L;
        L=s;
        return true;
    }
    LNode *p;
    // 由于不带头结点，这里L即是头结点，位序从1开始
    int j=1;
    p = L;
    // 接下来的操作和带头结点相同
    return true;
}

// 指定节点p的后插操作
bool InsertNextNode(LNode *p, ElemType e){
    if(p==NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 指定结点的前插操作
bool InsertPriorNode(LNode *p, ElemType e){
    if(p == NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL);
        return false;
    // 后插但偷天换日
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 带头结点的按位序删除
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    LNode *p;
    int j = 0;
    p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    // 注意要新声明一个节点并暂时保存要删除的结点和数据
    LNode *s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}

// 删除指定结点p
bool DeleteNode(LNode *p){
    if(p == NULL)
        return false;
    // 目前该算法还无法删除最后一个结点
    else if(p->next == NULL)
        return false;
    // 偷天换日
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 按位查找，返回第i个元素
LNode *GetElem(LinkList L, int i){
    // 可以返回头结点
    if(i<0)
        return NULL;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    return p;
}

// 按值查找，找到数据域等于e的结点
LNode *LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while(p!=NULL){
        if(p->data == e)
            return p;
        p = p->next;
    }
    return NULL;
}

// 求表长
int Length(LinkList L){
    LNode *p=L;
    int length = 0;
    while(p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int e;
    if(!InitList2(L)) return NULL;
    LNode *r = L;
    cin >> e;
    while(e!=0){
        if(!InsertNextNode(r,e)) return L;
        r=r->next;
        cin >> e;
    }
    r->next = NULL;
    return L;
}

// 头插法建立单链表，具有实现链表逆置的优势
LinkList List_HeadInsert(LinkList &L){
    int e;
    if(!InitList2(L)) return NULL;
    cin >> e;
    while (e!=0){
        if(!InsertNextNode(L,e)) return L;
        cin >> e;
    }
    return L;
}

// 当L初始化为不带头结点的单链表时，L是否指向NULL也是判空依据
bool Empty(LinkList L){
    if(L == NULL)
        return true;
    else
        return false;
}

// L初始化为带头结点的单链表，判空对象为L的下一个结点
bool Empty2(LinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

void ListPrint(LinkList L){
    LNode *p=L->next;
    while(p!=NULL){
        cout << p->data;
        if(p->next!=NULL)
            cout << "->";
        p=p->next;
    }
    cout << endl;
}

int main(){
    LinkList L;
    int e;
    L = List_TailInsert(L);
    ListPrint(L);
    // L = List_HeadInsert(L);
    // ListPrint(L);
    ListInsert(L,3,10);
    ListDelete(L,3,e);
    ListPrint(L);
    free(L);
    return 0;
}