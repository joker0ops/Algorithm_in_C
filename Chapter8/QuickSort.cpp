#include <iostream>
using namespace std;

int Partition(int A[], int low, int high)
{
    // 选择待处理表中的第一个元素作为基准
    int pivot = A[low];
    // 对待处理表进行一次划分，直到low=high时停止
    while (low < high)
    {
        // 先移动high，保证每个A[high]均大于等于基准
        while (low < high && A[high] >= pivot)
            high--;
        // 如果不满足则把该值移到左端
        A[low] = A[high];
        // 移动low，保证每个A[low]都小于基准
        while (low < high && A[low] < pivot)
            low++;
        // 比基准大的移到右端
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high)
{
    // 递归跳出的条件，low=high，此时待处理的表中只有一个元素
    if (low < high)
    {
        int pivotpos = Partition(A, low, high); // 划分
        QuickSort(A, low, pivotpos - 1);        // 划分左子表
        QuickSort(A, pivotpos + 1, high);       // 划分右子表
    }
}

/*

效率分析：
快速排序每一次划分时间复杂度不超过O(n)，时间复杂度=O(n*递归层数)
可以将快速排序过程处理为一颗二叉树，那么把n个元素组织成二叉树，二叉树的层数就是递归调用的层数
n个结点的二叉树最小高度为[log2n]+1（向下取整），最大高度为n，空间复杂度和递归层数成正比。
如果选取第一个元素作为基准元素，则初始序列有序或逆序都会使得快速排序性能最差，优化方法是选取头、中、尾
三个位置的元素，取中间值作为基准元素，或在列表中随机选一个作为基准元素。

*/