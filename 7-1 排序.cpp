#include <iostream>
#include <stdio.h>
using namespace std;

void GetArr(int arr[],int n)
{
    int i;
    for(i = 1; i < n; i++)
    {
//        cin>>arr[i];
        scanf("%d",&arr[i]);
    }
}
void Print(int arr[],int n)
{
    int i;
    printf("%d",arr[1]);
//    cout<<arr[1];
    for(i = 2; i < n; i++)
    {
        printf(" %d",arr[i]);
//        cout<<" "<<arr[i];
    }
//    cout<<endl;
    printf("\n");
}

//当一个数组名作为函数参数时，数组名的值就是指向数组第一个元素的指针，所以此时传递给函数的是指针的拷贝。
int Partition(int arr[], int low, int high)
{
    arr[0] = arr[low];
    int privotKey = arr[low];//基准元素
    while(low < high)//从表的两端交替向中间扫描
    {
        //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
        while(low < high && arr[high] >= privotKey)
            --high;
        arr[low] = arr[high];
        while(low < high && arr[low] <= privotKey)
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = arr[0];
//    Print(arr,10);
    return low;
}
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int privotLoc = Partition(arr, low, high);//将表一分为二
        QuickSort(arr, low, privotLoc-1);//递归对低子表递归排序
        QuickSort(arr, privotLoc+1, high);//递归对高子表队规排序
    }
}

int N;
int main()
{
    cin>>N;
    int arr[N+1];
    GetArr(arr, N+1);
    QuickSort(arr, 1, N);
    Print(arr,N+1);
}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//void Print(int arr[],int n)
//{
//    int i = 0;
//    cout<<arr[0];
//    for(i = 1; i < n; i++)
//    {
//        cout<<" "<<arr[i];
//    }
//    cout<<endl;
//}
//int main()
//{
//    int N,i;
//    cin>>N;
//    int  arr[N];
//    for(i = 0; i < N; i++)
//    {
//        cin>>arr[i];
//    }
//    sort(arr,arr+N);
//    Print(arr, N);
//}







#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 1000;
int a[maxn];
int quick_ss(int low,int high)
{
    a[0] = a[low];
    int tmp = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= tmp)
            high--;
        a[low] = a[high];
        while(low < high&& a[low] <= tmp)
            low++;
        a[high] = a[low];
    }
    a[low] = a[0];
    return low;
}
void quick_sort(int low,int high)
{
    if(low < high)
    {
        int mid = quick_ss(low,high);
        quick_sort(low,mid-1);
        quick_sort(mid+1,high);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    }
    quick_sort(1,n);
    for(int i = 1; i <= n; i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}










#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
void BubbleSort(int data[],int N)//冒泡排序 样例45678过不了
{
    int tmp;
    for(int i=0; i<N-1; i++)
    {
        for(int j=1; j<N; j++)
        {
            if(data[j]<data[j-1])
            {
                tmp = data[j-1];
                data[j-1] = data[j];
                data[j] = tmp;
            }
        }
    }
}
void InsertSort(int data[],int N)//直接插入排序 样例6过不了
{
    int tmp,j;
    for(int i=1; i<N; i++)
    {
        tmp = data[i];
        for(j=i; j>0&&data[j-1]>tmp; j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }
}
void BInsertSort(int data[],int N)//折半插入排序
{
    int tmp,j;
    for(int i=1; i<N; i++)
    {
        tmp = data[i];
        int low = 0,high = i-1;
        while(low<=high)
        {
            int m = (low+high)/2;
            if(data[m]>data[i])high = m-1;
            else low = m+1;
        }
        //cout<<low<<endl;
        //  int flag=1;
        for(j=i; j>low; j--)
        {
            //flag=0;
            data[j]=data[j-1];
        }
        // cout<<flag<<endl;
        data[low] = tmp;
    }
    //cout<<endl;
}
void ShellInsert(int data[],int N)//希尔排序 样例全过
{
    /*for(int gap=N/2; gap>0; gap/=2)//增量逐渐减少
    {
        for(int i=0; i<gap; i++)
        {
            for(int j=i+gap; j<N; j+=gap)
                if(data[j]<data[j-gap])
                {
                    int tmp  = data[j];
                    int k = j-gap;
                    while(k>=0&&data[k]>tmp)//记录后移，直到找到插入位置
                    {
                        data[k+gap] = data[k];
                        k-=gap;
                    }
                    data[k+gap] = tmp;
                }
        }
    }*/
    //简化：
    for(int gap=N/2; gap>0; gap/=2)//增量逐渐减少
    {
        for(int j=gap; j<N; j++)
            if(data[j]<data[j-gap])
            {
                int tmp  = data[j];
                int k = j-gap;
                while(k>=0&&data[k]>tmp)//记录后移，直到找到插入位置
                {
                    data[k+gap] = data[k];
                    k-=gap;
                }
                data[k+gap] = tmp;
            }

    }


    for(int gap = N/2; gap >0; gap/=2);
    for(int j = gap; j< N; j++)
    {
        if(data[j] < data[j-gap])
        {
            int tem = data[j];
            int k = j-gap;
            while(k >= 0 && data[k] > tem)
            {
                data[k+gap] = data[k];
                k-=gap;
            }
            data[k+gap] = tem;
        }
    }

}
void Print(int data[],int N)
{
    cout<<data[0];
    for(int i=1; i<N; i++)
        cout<<' '<<data[i];
}
//快速排序
int Partition(int data[],int low,int high)
{
    int tmp = data[low];
    int prvokey = data[low];
    while(low<high)
    {
        while(low<high&&data[high]>=prvokey)--high;
        data[low] = data[high];
        while(low<high&&data[low]<=prvokey)++low;
        data[high] = data[low];
    }
    data[low] = tmp;
    return low;
}
void Qsort(int data[],int low,int high)
{
    if(low<high)
    {
        int pivotloc = Partition(data,low,high);
        Qsort(data,low,pivotloc-1);
        Qsort(data,pivotloc+1,high);
    }
}
void QuickSort(int data[],int N)
{
    Qsort(data,0,N-1);
}
//简单选择排序
void SelectSort(int data[],int N)
{
    for(int i=0; i<N; i++)
    {
        int k=i;
        for(int j=i+1; j<N; j++)
            if(data[j]<data[k])
                k=j;
        if(k!=i)
        {
            int tmp = data[i];
            data[i] = data[k];
            data[k] = tmp;
        }
    }
}
//堆排序
void HeapAdjust(int data[],int s,int m)
{
    int rc=data[s];//取出根节点
    for(int j=2*s; j<=m; j*=2)
    {
        if(j<m&&data[j]<data[j+1])j++;
        if(rc>=data[j])break;
        data[s]=data[j];
        s=j;
    }
    data[s]=rc;

}

void CreatHeap(int data[],int N)
{
    for(int i=N/2-1; i>=0; i--) //建立大根堆，由于下标从0开始，最后一个元素的父节点是N/2-1
        HeapAdjust(data,i,N);
}
void HeapSort(int data[],int N)
{
    CreatHeap(data,N);
    for(int i=N-1; i>0; i--)
    {
        int x=data[0];//将堆顶记录和当前未经排序子序列中的最后一个记录互换
        data[0]=data[i];
        data[i]=x;
        HeapAdjust(data,0,i-1);
    }
}
//归并排序
void Merge(int A[], int TmpA[], int L, int R, int RightEnd )
{
    //将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列
    int LeftEnd, NumElements, Tmp;
    int i;
    LeftEnd = R - 1;    //左边终点位置
    Tmp = L;    //有序序列的起始位置
    NumElements = RightEnd - L + 1;     //元素总个数
    while( L <= LeftEnd && R <= RightEnd )
    {
        if( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++];   //将左边元素复制到TmpA
        else
            TmpA[Tmp++] = A[R++];   //将右边元素复制到TmpA
    }
    while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++];   //直接复制左边剩下的
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++];   //直接复制右边剩下的
    for( i = 0; i < NumElements; i++, RightEnd-- )
        A[RightEnd] = TmpA[RightEnd];   //将有序的TmpA复制回A
}
void Msort(int R[],int T[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        Msort(R,T,low,mid);
        Msort(R,T,mid+1,high);
        Merge(R,T,low,mid+1,high);
    }
}
void MergeSort(int data[],int N)
{
    int tmpA[N];
    Msort(data,tmpA,0,N-1);
}
int main()
{
    int N,M;
    int data[MAX];
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&data[i]);
    }
    //BubbleSort(data,N);
    //InsertSort(data,N);
    //BInsertSort(data,N);
    ShellInsert(data,N);
    //QuickSort(data,N);
    //SelectSort(data,N);
    //HeapSort(data,N);
    //MergeSort(data,N);
    //Print(data,N);
    if(N<M)M=N;
    printf("%d",data[N-1]);
    for(int i=1; i<M; i++)
        printf(" %d",data[N-i-1]);
    return 0;
}
