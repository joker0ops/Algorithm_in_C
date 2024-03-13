/*
问题描述：
给定N个整数的序列A，求这个序列中从Ai到Aj的子列的和，并找出拥有最大和的子列，若最大子列和小于0，则返回0.
*/

#include<iostream>
using namespace std;

/*
    第一个算法最为简单，将i作为子列的左端，将j作为子列的右端遍历出所有子列。然后通过k将子列中的各项累加起来并与当前最大子列和做对比，
    超过了则替换最大子列和。
    但是此方法存在着极大的弊端，首先就是时间复杂度过高(达到了O(n³))，而且我们可以发现k的存在致使每次求子列和时都会从i到j重新求一遍，
    而求下一个子列和只需要在前一个子列和的基础上进行累加即可，于是我们有了第二个算法。
*/
int MaxSubseqSum1 (int A[], int N){ 
    int Thissum, Maxsum = 0;
    int i, j, k;
    /*i是子列左端位置*/
    for (i=0; i<N; i++){
        /*j是子列右端位置*/
        for(j=i; j<N; j++){
            /*Thissum是从A[i]到A[j]的子列和*/ 
            Thissum = 0; 
            for (k = i; k<=j; k++)
                Thissum += A[k] ;
            if(Thissum>Maxsum) /*如果刚得到的这个子列和更大*/
            Maxsum =Thissum ;/*则更新结果*/
        }/*j循环结束*/
    }/*i循环结束*/
    return Maxsum ;
}

/*
    第二个算法取消了算法一的k造成的时间浪费，求子列和时直接在上一个子列和的基础上进行累加并与当前最大子列和做对比。但仍有O(n²)的时间复杂度
*/
int MaxSubseqSum2(int A[], int N){
    int ThisSum, MaxSum=0;
    for(int i=0;i<N;i++){
        // 注意这里当前子列和的初始化位置
        ThisSum=0;
        for(int j=i;j<N;j++){
            ThisSum+=A[j];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}

// 分治法求最大子列和，时间复杂度为O(nlogn)
// 返回左端最大子列和，右端最大子列和以及跨越中点的最大子列和的最大值
int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer( int List[], int left, int right )
{ /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }

    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

/*  
    实时处理算法：每读取一个输入就进行及时的处理，在任何一个地方终止输入，算法都能够正确地给出当前状态下的解
*/
int startflag=0, endflag;
void MaxSubseqSum4( double A[], int N ){
    double ThisSum=0, MaxSum=0;
    for(int i=0; i<N; i++){
        // 由于所要求的是连续子列和，因此需要不断累加
        ThisSum += A[i];
        // 若当前子列和大于最大子列和，那么更新最大子列和
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;
            endflag = i;
        }
        // 若当前子列和小于0，则该子列对于求出最大子列和只能起反作用，因此舍弃之并进行下一轮循环
        else if( ThisSum < 0 ){
            ThisSum = 0;
            startflag = i+1;
        }
    }
    cout << "Maxsum = " << MaxSum << " startflag = " << startflag << " endflag = " << endflag << endl; 
}

int main(){
    int n;
    cin >> n;
    double A[n];
    for(int i=0;i<n;i++)
        cin >> A[i];
    MaxSubseqSum4(A,n);
    return 0;
}