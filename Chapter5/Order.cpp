#include <iostream>
using namespace std;
typedef struct BiNode
{
    int data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
// 先序
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        cout << T->data;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
// 中序
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        cout << T->data;
        InOrder(T->rchild);
    }
}
// 后序
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data;
    }
}
// 应用：求树的深度
int treeDepth(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        // 树的深度=Max(左子树的深度，右子树的深度) + 1;
        return l > r ? l + 1 : r + 1;
    }
}
// 层序
/*
    算法思想：
    1、初始化一个辅助队列
    2、根节点入队
    3、若队列非空，则对头结点出队并访问该结点，然后将其左右孩子插入队尾
    4、重复3直到队列为空
*/
typedef struct LinkNode
{
    // 存储指向二叉树结点的指针而不是二叉树结点
    BiNode *data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    // 队头队尾指针
    LinkNode *front, *rear;
} LinkQueue;
/*
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);    // 初始化辅助队列
    BiNode *p;
    EnQueue(Q,T);   // 根节点入队
    while(!is_empty(Q)){
        DeQueue(Q, p);  // 队头结点出队
        visit(p);       // 访问出队结点
    if(p->lchild!=NULL)
        EnQueue(Q, p->lchild);  // 左孩子出队
    if(p->rchild!=NULL)
        EnQueue(Q, p->rchild);  // 右孩子入队
    }
}
*/