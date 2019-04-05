//#include <iostream>
//using namespace std;
//
//void GetArr(int arr[],int n)
//{
//    int i;
//    for(i = 0; i < n; i++)
//    {
//        cin>>arr[i];
//    }
//}
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
//void Swap(int *a, int *b)
//{
//    int tem = *a;
//    *a = *b;
//    *b = tem;
//}
//int Partition(int arr[], int low, int high)
//{
//    int privotKey = arr[low];//基准元素
//    while(low < high)//从表的两端交替向中间扫描
//    {
//        //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
//        while(low < high && arr[high] >= privotKey)
//            --high;
////        cout<<arr[low]<<" "<<arr[high]<<" ";
//        Swap(&arr[low],&arr[high]);
////        cout<<arr[low]<<" "<<arr[high]<<endl;
//
//        while(low < high && arr[low] <= privotKey)
//            ++low;
//        Swap(&arr[low],&arr[high]);
//    }
////    Print(arr,10);
//    return low;
//}
//void QuickSort(int arr[], int low, int high)
//{
//    if(low < high)
//    {
//        int privotLoc = Partition(arr, low, high);//将表一分为二
//        QuickSort(arr, low, privotLoc-1);//递归对低子表递归排序
//        QuickSort(arr, privotLoc+1, high);//递归对高子表队规排序
//    }
//}
//int main()
//{
//    int N,M;
//    cin>>N>>M;
//    if(N < M)
//        M = N;
//    int arr[N];
//    GetArr(arr, N);
//    QuickSort(arr, 0, N-1);
//    int i;
//    cout<<arr[N-1];
//    for(i = N-2; i >= N-M; i--)
//    {
//        cout<<" "<<arr[i];
//    }
//    return 0;
//}
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int N,M,i;
//    cin>>N>>M;
    //scanf要比cin快很多，大量数据的输入最好用scanf
    scanf("%d%d",&N,&M);
    if(N < M)
        M = N;
    int arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N);
    printf("%d",arr[N-1]);
    for(i = N-2; i >= N-M;i--)
    {
        printf(" %d",arr[i]);
    }
}
