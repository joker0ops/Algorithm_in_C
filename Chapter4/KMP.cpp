#include <iostream>
using namespace std;
#define MAXLEN 255
// 定长顺序存储，每个char字符占1B
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;
/*
    朴素模式匹配算法的漏洞在于，每次发现不匹配之后i指针都要回溯到起始位置，而没有记忆前面n-1个已匹配的字符
    KMP算法防止了指针i的回溯，而是在每次匹配失败时调整j的值
    j的回溯情况：
    1. 当j=1时发生不匹配应当j不变而i++，这里为了代码编写方便设置next[1]=0，然后在循环中加回来
    2. 当j=k时发生不匹配，说明前k-1个字符已经匹配成功，只需关注模式串前缀和后缀相同的位数
*/
int KMP(SString S, SString T)
{
    int i = 1, j = 1;
    int next[T.length + 1];
    int nextval[T.length + 1];
    // O(m)
    get_next(T, next);
    // get_nextval(T, next, nextval);
    // O(n)
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
    // 算法平均时间复杂度O(m+n)
}
/*
    j 
    google
     i
    google
1. 设置next[2]=1，从第二个位置开始不匹配，因此只有第一位匹配，j=1
2. 

*/
void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
/*

*/
void get_nextval(SString T, int next[], int nextval[])
{
    nextval[1] = 0;
    for (int j = 2; j <= T.length; j++)
    {
        if (T.ch[next[j]] == T.ch[j])
            nextval[j] = nextval[next[j]];
        else
            nextval[j] = next[j];
    }
}

int main()
{
    return 0;
}