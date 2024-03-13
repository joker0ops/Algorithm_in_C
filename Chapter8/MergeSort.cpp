#include<iostream>
using namespace std;
int n;
int *B = (int *)malloc(sizeof(int)*n);

void Merge(int A[], int low, int high, int mid){
    int i,j,k;
    for(k=low; k<=high; k++)
        B[k]=A[k];
    for(i=low, k=low, j=mid+1; i<=mid && j<=high; k++){
        if(B[i]<=B[j])
            A[k]=B[i++];
        else
            A[k]=B[j++];
    }
    while(j<=high) A[k++]=B[j++];
    while(i<=mid) A[k++]=B[i++];
}

void MergeSort(int A[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        // 归并
        Merge(A, low, high, mid);
    }
}

int main(){
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++)
        cin >> A[i];
    MergeSort(A, 0, n-1);
    for(int j=0; j<n; j++)
        cout << A[j] << " ";
    return 0;
}