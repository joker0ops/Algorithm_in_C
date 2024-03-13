/****************************************************************************
                                             n
    卡特兰数：n个元素不同出栈排列数=[1/(n+1)]*C
                                             2n
    栈的基本操作：
    InitStack(&S)
    StackEmpty(S)
    Push(&S,x)
    Pop(&S,&x)
    GetTop(S,&x)
    DestroyStack(&S)
    初始化时：S.top=-1;
    栈空条件：S.top==-1;
    栈满条件：S.top==MaxSize-1;
    栈长：S.top+1;

    共享栈：
    栈空：0号栈top0=-1; 1号栈top1=MaxSize;
    栈满：top1-top0==1;
    
    链栈：
    没有头结点，Lhead指向栈顶元素
    typedef struct LinkNode{
        ElemType data;
        struct LinkNode *next;
    } *LiStack;
    // 入栈和出栈操作均在表头进行

    队列基本操作：
    InitQueue(&Q)
    QueueEmpty(Q)
    EnQueue(&Q, x)
    DeQueue(&Q, &x)
    GetHead(Q, &x)

    顺序队列：
    #define MaxSize 100
    typedef struct{
        ElemType data[MaxSize];
        int front, rear;
    }SqQueue;
    队空条件：Q.front==Q.rear==0
    进队：Q.rear=(Q.rear+1)%MaxSize;队尾是允许入队的一边
    出队：Q.front=(Q.front+1)%MaxSize;队头是允许出队的一边
    队列长度：(Q.rear + MaxSize - Q.front)%MaxSize;

    判断队满条件：
    1、牺牲一个单元：(Q.rear+1)%MaxSize==Q.front
    2、增设Q.size：Q.size==MaxSize
    3、增设tag成员：出队时tag=0，入队时tag=1;
       若tag=0&&Q.rear==Q.front则为队空
       若tag=1&&Q.rear==Q.front则为队满

    链式队列：
    typedef struct LinkNode{
        ElemType data;
        struct LinkNode *next;
    }LinkNode;
    typedef struct{
        LinkNode *front, *rear;
    }LinkQueue;
    当且仅当Q.front==NULL&&Q.rear==NULL时队列为空（注意这里不能写Q.front==Q.rear==NULL，仔细想一下为什么）

    双端队列的逻辑：
    进队时，前端进的元素排列在队列中后端进的元素的前面，后端进的元素排列在队列中前端进的元素的后面
    出队时，无论是前端还是后端出队，先出的元素排列在后出的元素前面

    括号匹配逻辑：
    1、遇到左括号进栈，遇到右括号出栈栈顶的左括号进行比较
    2、若匹配了所有的右括号而栈非空，则左括号单身，匹配失败
    3、若栈已空而还有剩余的右括号，则右括号单身，匹配失败
    4、若出栈左括号后发现左右括号不匹配则匹配失败

    表达式求值问题：
    看王道的PDF

    栈在递归中的应用：最后被调用的函数最先执行结束

    队列的应用：
    1、广度优先遍历
    2、操作系统先来先服务FCFS可以用队列实现

    特殊矩阵的压缩存储：
    看王道PDF
****************************************************************************/