#include <iostream>
using namespace std;

void ShellSort(int A[], int n)
{
    int d, i, j, k;
    /*
        d代表间距
        k代表间距为d时的第k个子序列
        ij用来在子序列中使用插入排序
    */
    for (d = n / 2; d >= 1; d = d / 2)
    {
        for (k = 1; k <= d; k++)
        {
            for (i = k + d; i <= n; i += d)
            {
                if (A[i] < A[i - d])
                {
                    A[0] = A[i];
                    for (j = i - d; A[j] > A[0] && j > 0; j -= d)
                        A[j + d] = A[j];
                    A[j + d] = A[0];
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n + 1];
    A[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    ShellSort(A, n);
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    return 0;
}