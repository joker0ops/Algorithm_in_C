#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectSort(int A[], int n)
{
    // 总共有n-1趟
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        // 从第i个元素开始遍历，记录每一趟的最小元素的位置
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min])
                min = j;
        // 每一趟把最小元素交换到已排序序列的尾部
        if (min != i)
            swap(A[i], A[min]);
    }
}

/*
    时间复杂度O(n^2)
    如果空间复杂度增加到O(n)可以使时间复杂度降低到O(n)
    空间复杂度O(1)
    不稳定
*/