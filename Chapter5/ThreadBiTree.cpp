#include <iostream>
using namespace std;
// 线索二叉树
typedef struct ThreadNode
{
    int data;
    struct ThreadNode *rchild, *lchild;
    int ltag, rtag; // 左、右线索标志
    /*
        tag=0，表示指针指向孩子
        tag=1，表示指针指向线索（前序、中序、后序）
    */
} ThreadNode, *ThreadTree;
/*
    若没有线索二叉树，如何找结点p的前驱或后继
    适用遍历算法，指针q记录当前访问的结点，指针pre记录上一次访问的结点
    当p==q时，pre是前驱，当pre=p时，q是后继
    举例：查找中序的前驱
    BiNode *pre = NULL;
    q始终指向当前处理结点，pre指向上一个处理的结点
    int Flag=0;
    BiNode *FindPre(BiNode *q, BiNode *pre){
        若q不为空且q不是
        if(q!=NULL&&q!=p){
            BiNode *outcome=FindPre(q->lchild, pre);
            if(Flag==1)
                return outcome;
            pre=q;
        }
        else if(q!=NULL&&q==p){
            Flag=1;
            return pre;
        }
        else
            return NULL;
    }
    优化版本：
    BiNode *p;
    BiNode *pre=NULL;
    BiNode *final=NULL;
    void visit(BiNode *q){
        if(q==p)
            final=pre;
        else
            pre=q;
    }
    void InOrder(BiTree T){
        if(T!=NULL){
            InOrder(T->lchild);
            visit(T);
            InOrder(T->rchild);
        }
    }
*/
// 二叉树的中序线索化
// 保证第一个结点的前驱为空
ThreadNode *pre = NULL;
void visit(ThreadNode *q)
{
    // 此时pre是q的前驱结点，尝试用q的左子树构造前驱线索
    if (q->lchild == NULL)
    {
        q->lchild = pre;
        // 修改标志位表明指向为线索
        q->ltag = 1;
    }
    // 此时q是pre的后继结点，尝试用pre的右子树构造后继线索
    // 小Tips：如果不确定判断条件时可以先写内部语言再写判断条件
    if (pre != NULL && pre->rchild != NULL)
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
}
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}
// 对二叉树进行中序线索化
void CreateInThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T);
        // 线索化函数结束后pre和q最终会共同指向最后一个结点，这个结点没有后继，但其右子树为空，因此需要将其rtag置1
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}