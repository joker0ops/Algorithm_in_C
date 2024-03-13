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
串的顺序存储方案
1. 地址为MAXLEN处存放length
2. ch[0]充当length
3. 没有length变量，以字符'\0'表示结尾
4. ch[0]废弃不用，地址为MAXLEN处存放length（教材即以下基本操作中使用）
*/

// 堆分配存储
typedef struct
{
    char *ch;
    int length;
} HString;
/*
HString S;
S.ch = (char*)malloc(MAXLEN*sizeof(char));
S.length=0;
*/

// 串的链式存储
typedef struct StringNode
{
    char ch[4];
    struct StringNode *next;
} StringNode, *String;
/*
为了提高存储密度，一个结点中要放置多个字符
*/

// 求子串：用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    // 使用教材存储方式，字符的位序等于字符串序号
    // len=last-pos+1 -> last=pos+len-1
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
    {
        // 子串Sub从1开始，主串S从pos开始
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

// 比较操作：若S>T则返回值大于0；若S<T则返回值小于0；若S=T则返回值等于0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

// 定位操作：若主串S中存在与串T相同的子串，则返回它在主串S中第一次出现的位置；否则返回0
int Index(SString S, SString T)
{
    int i = 1, n = S.length, m = T.length;
    // 用于暂存子串
    SString sub;
    // 每次从S中取m位与T对比，最后取得的m位的第一位为n-m+1
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            i++;
        else
            return i;
    }
    // S中不存在与T相等的子串
    return 0;
}

// 串的朴素模式匹配算法1
int Index1(SString S, SString T)
{
    // k用来记录模式串在主串中可能匹配成功的第一次出现先位置
    int k = 1;
    int i = k, j = 1;
    while (i <= S.length && j <= T.length)
    {
        // 如果当前ij所指字符相同，则继续匹配下一位字符
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        // 若当前ij所指字符不同，则k当前位置不可能是匹配成功的T的位置，k++
        else
        {
            k++;
            i = k;
            j = 1;
        }
    }
    if (j > T.length)
        return k;
    else
        return 0;
}

// 串的朴素模式匹配算法2
int Index2(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            // 当不匹配时，j相比于初始位置走了j-1步，需要回溯到最初的位置再向后移动一位
            i = i - (j - 1) + 1; // i=i-j+2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main()
{
    return 0;
}