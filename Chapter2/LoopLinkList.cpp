#include<iostream>
using namespace std;
#define ElemType int

typedef struct LLNode{
    ElemType data;
    struct LLNode *next;
}LNode, *LLinkList;

// 注意：若循环链表带头结点，则链表尾部指向循环链表的头结点而不是第一个结点

bool InitLList(LLinkList &L){
    L = (LLNode*)malloc(sizeof(LLNode));
    if(L == NULL)
        return false;
    L->next = L;
    return true;
}

// 一般让L指向循环链表的表尾元素会比较方便
bool isTail(LLinkList L, LNode *p){
    if(p->next == L)
        return true;
    else
        return false;
}

bool Empty(LLinkList L){
    if(L->next == L)
        return true;
    else
        return false;
}

typedef struct LDNode{
    ElemType data;
    struct LDNode *prior, *next;
}LDNode, *LDLinklist;

bool InitLDLinkList(LDLinklist &L){
    L = (LDNode*)malloc(sizeof(LDNode));
    if(L == NULL)
        return false;
    // 前驱后继均指向自身
    L->prior = L;
    L->next = L;
    return true;
}

bool InsertNextLDNode(LDNode *p, LDNode *s){
    s->next = p->next;
    // 不必考虑p->next是否到链表尾
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

bool Empty(LDLinklist L){
    if(L->next == L)
        return true;
    else
        return false;
}

int main(){

    return 0;
}