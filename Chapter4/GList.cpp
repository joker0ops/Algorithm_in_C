#include <iostream>
#define MaxSize 10
using namespace std;
// 注：结构体中嵌套共用体，可以不加共用体名，但内部元素不能重名
//----广义表的头尾链表存储表示----//
typedef enum
{
    ATOM,
    LIST
} ElemTag;
/*
表结点：| tag=1 | hp | tp |
原子结点：| tag=0 | atom |
*/
typedef struct GLNode
{
    ElemTag tag; // 公共部分，标识表结点还是原子结点
    // 使用共用体类型来区分表结点还是原子结点的内容，共用体内部元素占用同一块内存，调用者针对某个变量只能使用其中一个元素
    union
    {
        int atom; // atom用来表示原子结点的值
        struct
        {
            struct GLNode *hp, *tp;
        } ptr; // ptr结点用来标识表结点的内容，*hp是用来指向表头的指针，*tp是用来指向表尾的指针
    };
} * GList; // 广义表指针
//----广义表的扩展线性链表存储表示----//
typedef enum
{
    ATOM,
    LIST
} ElemTag;
/*
表结点：| tag=1 | hp | tp |
原子结点：| tag=0 | atom | tp |
这里tp不再指向表尾而是下一个链接的元素
*/
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        int atom;
        struct GLNode *hp; // 表结点的表头指针
    };
    struct GLNode *tp; // 相当于线性链表的next，指向下一个元素结点
} * GList;
int main()
{
    return 0;
}