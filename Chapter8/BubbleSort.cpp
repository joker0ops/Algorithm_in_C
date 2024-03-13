#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/*
    从最后两个元素开始互相比较，每次都把最小的元素冒泡到前面，每趟移动到最后时j-1=i
*/
void BubbleSort(int A[], int n)
{
    // 总共n-1趟
    for (int i = 0; i < n - 1; i++)
    {
        // 本趟是否发生交换的标志
        bool flag = false;
        // 每一趟把一个最小的元素冒泡到前面已排序序列
        // 从最后一个元素开始与前一个元素比较，直到i+1与i
        // 指针i不仅记录趟数，还要记录首部已经有i-1个已排序元素
        for (int j = n - 1; j > i; j--)
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        // 如果本次遍历后没有发生交换则说明表已经有序
        if (flag == false)
            return;
    }
}

/*
    最好时间复杂度O(n)：不发生交换
    最坏O(n^2)：每一趟都发生交换
    也可以用于链表
    稳定性稳定
*/