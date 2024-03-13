#include <iostream>
using namespace std;
#define ElemType int
typedef struct
{
    ElemType *elem;
    int TableLen;
} SSTable;

// 普通顺序查找
int Search_Seq(SSTable ST, ElemType key)
{
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; i++)
        ;
    // 查找成功，返回元素下标i，查找失败i必将移动到最后一个元素下标的后一位即elem[ST.TableLen]返回-1
    return i == ST.TableLen ? -1 : i;
}

// 顺序查找的实现（哨兵），无须判断是否越界，效率更高
int Search_Seq2(SSTable ST, ElemType key)
{
    // 第一个元素存储关键字，使得查找表元素的下标和位序相等
    ST.elem[0] = key;
    int i;
    // 从最后一个元素开始判断，直到i=0或查找成功时停止
    for (i = ST.TableLen; ST.elem[i] != key; --i)
        ;
    // 若查找成功则返回成功的i，查找失败返回0
    return i;
}