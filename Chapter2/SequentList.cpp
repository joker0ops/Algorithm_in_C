#include<iostream>
using namespace std;
#define ElemType int

typedef struct{
    ElemType* data;
    ElemType length;
    ElemType MAXSIZE;
}SeqList;

// 注意这里初始化给的是列表的最大长度而不是当前长度
bool initlist(SeqList &L, int initsize){
    L.MAXSIZE=initsize;
    L.data=new ElemType[initsize];
    L.length=0;
    if(L.data == NULL)
        return false;
    return true;
}

// 传入的i是位序，位序-1才是对应的下标
bool listinsert(SeqList &L, int i, int e){
    if(L.length>=L.MAXSIZE)
        return false;
    if(i>L.length+1||i<=0)
        return false;
    // 插入操作为后移递减
    for(int j=L.length;j>=i-1;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    // 一定注意这里
    L.length++;
    return true;
}

bool listdelete(SeqList &L, int i, int &e){
    if(i<=0||i>L.length)
        return false;
    e=L.data[i-1];
    // 按位删除操作为后移递增
    // 注意这里，由于我们只有L.length个数据，所以L.data[L.length]是脏数据，不可访问，第一种写法错误
    // for(int j=i-1;j<L.length;j++){
    //     L.data[j]=L.data[j+1]
    // }
    // 使用这种遍历方式是正常的
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

// 按值查找
int LocateElem(SeqList L, ElemType e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)
            return i+1;
    }
    return 0;
}

void printlist(SeqList L){
    for(int i=0;i<L.length;i++)
        cout << L.data[i] << " ";
    cout << endl;
}

int main(){
    SeqList L;
    int MAXSIZE = 20;
    bool flag = initlist(L, MAXSIZE);
    cout << flag << endl;
    cout << L.length << endl;
    cout << L.MAXSIZE << endl;
    for(int i=1; i<=10; i++){
        flag = listinsert(L, i, i);
        cout << "flag= " << flag << endl;
    }
    printlist(L);
    flag = listinsert(L, 11, 15);
    cout << "flag= " << flag << endl;
    printlist(L);
    // 删除非数组元素直接使用delete a;
    delete[] L.data;
    return 0;
}
