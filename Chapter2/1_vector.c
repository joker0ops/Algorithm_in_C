#include<stdio.h>
#include<stdlib.h> // 为malloc函数以及realloc函数提供支持
#include<time.h>   // 为Time函数提供支持

// 使用typedef将struct Vector数据类型转换为Vector类型
typedef struct Vector{
    // 创建一个int型的指针指向顺序表的首地址
    int *data;
    // size表示顺序表的总大小，length表示当前顺序表的长度
    int size,length;
} Vector;

// 初始化一个n个空间大小的int型顺序表
Vector *init(int n) {
    // 为什么要先开辟指针的空间？
    Vector *vec=(Vector*)malloc(sizeof(Vector)); // 先申请一个顺序表的空间
    vec->data = (int*)malloc(n*sizeof(int)); // 申请顺序表中连续存储区的空间
    vec->size = n;
    vec->length = 0;
    return vec;
}

/* 初代函数，若当前数据表满了则无法改动，未解决数组固定大小的问题
 顺序表的插入操作，ind代表要插入的位置，val代表要插入的值
int insert(Vector *vec, int ind, int val){
     在数据结构创建后的每个执行函数要先判断操作的合法性，下同
     当数据表为空时不可插入
    if(vec == NULL) return 0;           
     当插入的位置在0前或在最后一个元素（length-1）的后两位及以上时不可插入
    if(ind<0||ind>vec->length) return 0;
     当顺序表满时不可插入
    if(vec->length==vec->size) return 0;
     把ind后面的元素循环向后移一位《！！！从后往前遍历》
    for(int i=vec->length-1;i>=ind;i--)
        vec->data[i+1]=vec->data[i];
    vec->data[ind]=val;
    vec->length++;
    return 1;
}
*/

// 顺序表扩容，易造成内存泄漏（若realloc申请不成功，则会返回NULL到vec->data，丢失了原始数据）
int expand2(Vector *vec){
    vec->size*=2;
    vec->data = (int*)realloc(vec->data, sizeof(int)*vec->size);
    return 1;
}
// 顺序表扩容，不会造成内存泄漏
int expand(Vector *vec){
    int new_size = vec->size * 2;
    int *p = (int*)realloc(vec->data, sizeof(int)*new_size);
    // 若申请失败则退出
    if (p == NULL) return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

// 顺序表的插入操作，ind代表要插入的位置，val代表要插入的值
// 二代插入函数，改进了数据表满时的情况
int insert(Vector *vec, int ind, int val){
    // 在数据结构创建后的每个执行函数要先判断操作的合法性，下同
    // 当数据表为空时不可插入
    if(vec == NULL) return 0;           
    // 当插入的位置在0前或在最后一个元素（length-1）的后两位及以上时不可插入
    if(ind<0||ind>vec->length) return 0;
    // 当顺序表满时执行扩容操作，当扩容失败时才返回
    if(vec->length==vec->size){
        if(!expand(vec)) return 0;
        // 输出顺序表扩容之后的大小
        printf("expand vector size to %d successfully!\n",vec->size);
    }
    // 把ind后面的元素循环向后移一位《！！！从后往前遍历》
    for(int i=vec->length-1;i>=ind;i--)
        vec->data[i+1]=vec->data[i];
    vec->data[ind]=val;
    vec->length++;
    return 1;
}

// 顺序表的删除操作
int erase(Vector *vec, int ind){
    // 当数据表为空时不可删除
    if(vec == NULL) return 0;
    // 当顺序表为空时不可删除
    if(vec->length==0) return 0;
    // 当删除位置在0前或在最后一个元素之后时不可插入
    if(ind<0||ind>=vec->length) return 0;
    // 将ind后面的元素循环向前移一位《！！！这里才是向后遍历》
    for(int i = ind + 1;i<vec->length;i++)
        vec->data[i - 1]=vec->data[i];
    /* 错误示例：
    for(int i=ind;i<vec->length;i++)
        vec->data[i]=vec->data[i+1];
    i+1最后会遍历到下标length位，这一位没有元素
    */
    vec->length--;
    return 1;
}

// 释放顺序表的空间
void clear(Vector *vec){
    // 如果顺序表为空，则直接返回
    if(vec==NULL) return ;
    // 否则，先释放连续存储区的空间
    free(vec->data);
    // 再释放顺序表的空间
    free(vec);
    return ;
}

// 输出数据表
void output(Vector *vec){
    printf("array(%d) = [",vec->length);
    for(int i=0; i<vec->length;i++){
        // 从第二个元素开始每个元素后面打印一个逗号
        if(i!=0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

int main(){
    // 定义最大的操作次数<!!!宏定义不要加;>
    #define MAX_OP 20
    // 传入当前系统时间作为随机种子
    srand(time(0));
    Vector *vec = init(1);
    int op, ind, val;
    for(int i=0; i<MAX_OP; i++){
        op=rand() % 2;  // 通过模2使得随机数范围固定在0或1
        // 将位置随机数范围控制在顺序表长度之内，必须＋1，模0是非法的！
        ind=rand() % (vec->length + 1);
        val=rand() % 100;
        switch (op){
            case 0:
            // 执行插入操作并输出返回值
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            break;
            case 1:
            // 执行删除操作并输出返回值
                printf("erase item at %d from vector = %d\n", ind, erase(vec, ind));
            break;
        }
        output(vec);
    }
    return 0;
}
/*
malloc函数以及realloc函数详解：

malloc函数：
函数原型：void *malloc(unsigned int num_bytes);
num_bytes -- 内存块的大小，以字节为单位。
malloc函数固定返回void*类型的指针，使用时一般通过强制转换将固定其返回的指针类型
如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL，并且当内存不再使用时，应通过free()函数释放内存

realloc函数：
函数原型：extern void *realloc(void mem_address, unsigned int newsize);
指针名=（数据类型）realloc（要改变内存大小的指针名，新的大小）。

先判断当前的指针是否有足够的连续空间，如果有，扩大mem_address指向的地址，并且将mem_address返回，
若空间不足，则调用malloc申请一段新的空间，若申请成功，则将原空间的数据拷贝到新空间并返回新空间，然后释放原空间
若仍出现空间不足，则返回NULL。
*/