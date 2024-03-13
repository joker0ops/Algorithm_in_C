#include <iostream>
using namespace std;
#define ElemType int
typedef struct
{
    ElemType *elem;
    int TableLen;
} SSTable;
// 二分查找，仅适用于 <有序> 的 <顺序表> ，这里按增序表进行
int Binary_Search(SSTable L, ElemType key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2; // 中间位置向下取整
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    // 查找失败，返回-1
    return -1;
}