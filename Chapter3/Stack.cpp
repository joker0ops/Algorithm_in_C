#include<iostream>
using namespace std;
#define ElemType int
#define MaxSize 10
typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    /*
    另一种方式：S.top指向待插入数据的位置
    S.top = 0
    */
    S.top = -1;
}
bool EmptyStack(SqStack S){
    /*
    另一种方式：通过S.top是否为0判断栈是否为空
    */
    if(S.top == -1)
        return true;
    else
        return false;
}

// 新元素进栈
bool Push(SqStack &S, ElemType e){
    // 栈满报错
    /*
    另一种方式栈满的条件是S.top == MaxSize
    */
    if(S.top+1==MaxSize)
        return false;
    /*
    另一种方式需要先把元素入栈再将top++指向下一个待插入的位置
    */
    S.data[++S.top] = e;
    return true;
}

// 元素出栈
bool Pop(SqStack &S, ElemType &e){
    /* S.top == 0? */
    if(S.top == -1)
        return false;
    /*
    另一种方式需要先--S.top，再返回S.data[S.top]
    */
    e = S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack S, ElemType &e){
    if(S.top == -1)
        return false;
    /* S.data[S.top-1] */
    e = S.data[S.top];
    return true;
}

// 共享栈->两个栈共享同一片空间
typedef struct ShStack{
    ElemType data[MaxSize];
    int top0;
    int top1;
}ShStack;
    /*
    共享栈在初始化时，top0指向-1位置，top1指向MaxSize位置
    栈满的条件是top0+1 = top1
    */

// 链栈->使用链表建立栈
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}StackNode, *LinkStack;
    /*
    链栈的进栈对应于单链表对头结点的后插操作
    链栈的出栈对应于单链表对头结点的后删操作
    */

int main(){
    SqStack S;
    InitStack(S);
    return 0;
}