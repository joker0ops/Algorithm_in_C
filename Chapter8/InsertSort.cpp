#include <iostream>
using namespace std;

// 不带哨兵的插入排序（从小到大）
void InsertSort(int A[], int n)
{
    int i, j, temp;
    // 只需从第二个元素开始处理即可
    for (i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            temp = A[i];
            // 已经排号序的元素是从0到i-1，用temp存储当前A[i]然后从第i-1位开始凡是大于A[i]的依次向后移位
            for (j = i - 1; j >= 0 && A[j] > temp; --j)
                A[j + 1] = A[j];
            // 此时循环到A[j]不满足A[j]>temp，且A[j]未移动，因此把temp放在A[j+1]位
            A[j + 1] = temp;
        }
    }
}

// 带哨兵的插入排序，A[0]存储当前待排序元素，待排序序列从A[1]~A[n]
void InsertSort2(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            // 这里省略了一步越界的判断
            for (j = i - 1; A[j] > A[0]; j--)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
    }
}

/*

    根据算法可以分析时间复杂度主要来自移位及判断操作，最好的情况是序列原本就是有序的，此时不发生移位，时间复杂度是O(n)
    最坏的情况是待排序序列是逆序的：最坏时间复杂度O(n^2)
    平均时间复杂度：O(n^2)
    算法稳定性：稳定

*/

// 优化——折半插入排序，时间复杂度仍然是O(n^2)，只能用于顺序表
void HalfInsertSort(int A[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            int low = 1, high = i - 1, mid;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (A[mid] > A[0])
                    // 当中间值大于A[0]时，A[0]可能出现在左子表
                    high = mid - 1;
                else
                    // 当中间值小于A[0]时，A[0]可能出现在右子表
                    // 这里当A[mid]==A[0]时，为了保证算法的稳定性，继续在mid所指位置的右边寻找插入位置
                    low = mid + 1;
            }
            // 退出循环的前一个状态是high=mid=low，然后high=mid-1，此时A[low]=A[high+1]及其右边的值均大于A[0]，A[high]<=A[0]
            // 把A[low]向右移位
            for (int j = i - 1; j >= high + 1; j--)
                A[j + 1] = A[j];
            A[high + 1] = A[0];
        }
    }
}

// 对链表进行插入排序时，移动次数变少但关键字对比的次数依然是O(n^2)