/****************************************************************************

二叉树存储结构
1、顺序存储
    #define MaxSize 100
    struct TreeNode{
        // 结点中数据元素的值
        ElemType value;
        // 结点是否为空
        bool isEmpty;
    }
    struct TreeNode t[MaxSize];
    for(int i=0; i<MaxSize; i++){
        t[i].isEmpty=true;
    }
    顺序存储中（只适用完全二叉树，因此普通二叉树需要存储序号与完全二叉树对应）常考：
    i的左孩子   2i
    i的右孩子   2i+1
    i的父结点   i/2向下取整
    i所在的层次 log2(n+1)向上取整或(log2n)+1向下取整
    不管结点多少，只看高度，高度为h，则至少需要2

    判断i是否有左孩子？         2i<=n?
    判断i是否有右孩子？         2i+1<=n?
    判断i是叶子结点还是分支结点？i>n/2向下取整  <重中之重！！！>

2、链式存储
    typedef struct BiNode{
        ElemType data;
        struct BiNode *lchild, #rchild;
    }BiNode, *BiTree;
    // n个结点的二叉链表有n+1个空链域

3、二叉树的线索化：再看一遍王道-
****************************************************************************/