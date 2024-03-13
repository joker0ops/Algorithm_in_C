#include <iostream>
using namespace std;
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 在二叉排序树中寻找值为num的结点，也可以用递归实现，但空间复杂度变为O(h)
BSTNode *BST_Search(BSTree T, int num)
{
    // 要学会这种写法，在循环判断时添加未找到的条件，这样循环结束时要么找不到为空要么找到该结点，而不是在循环体中进行判断
    while (T != NULL && T->key != num)
    {
        if (T->key > num)
            T = T->lchild;
        else
            T = T->rchild;
    }
    // 我看哪个傻子搁这儿写注释
    return T;
}

// 二叉排序树的插入(递归实现)，最坏空间复杂度O(h)
int BST_Insert(BSTree &T, int k)
{
    if (T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = NULL;
        T->rchild = NULL;
        return 1;
    }
    else if (T->key > k)
        return BST_Insert(T->lchild, k);
    // k存在于BST中时插入失败返回0
    else if (T->key == k)
        return 0;
    else
        return BST_Insert(T->rchild, k);
}

// 二叉排序树的插入(循环实现)，最坏空间复杂度O(1)
int BST_Insert2(BSTree &T, int k)
{
    while (T->key != k)
    {
        if (T == NULL)
        {
            T = (BSTree)malloc(sizeof(BSTNode));
            T->key = k;
            T->lchild = NULL;
            T->rchild = NULL;
            return 1;
        }
        else if (T->key < k)
            T = T->rchild;
        else
            T = T->lchild;
    }
    return 0;
}

void InOrder_BST(BSTree T)
{
    if (T != NULL)
    {
        InOrder_BST(T->lchild);
        cout << T->key << " ";
        InOrder_BST(T->rchild);
    }
}

void Create_BST(BSTree &T, int str[], int n)
{
    for (int i = 0; i < n; i++)
        BST_Insert(T, str[i]);
}

int main()
{
    BSTree T = NULL;
    int n;
    cin >> n;
    int str[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    Create_BST(T, str, n);
    InOrder_BST(T);
    return 0;
}