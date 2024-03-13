#include<iostream>
#define ElemType int
#define MaxSize 10
// 队列的顺序实现
typedef struct queue{
    ElemType data[MaxSize];
    // front指向队头元素，rear指向下一个应该插入的位置
    int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

bool EmptyQueue(SqQueue Q){
    if(Q.rear == Q.front)
        return true;
    else
        return false;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    return 0;
}