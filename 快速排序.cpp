//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int Partition(int data[], int low, int high)
//{
//    int data[0] = data[low];
//    int tem = data[low];
//    while(low < high)
//    {
//        while(low < high && data[high] >= tem)
//            high--;
//        data[low] = data[high];
//        while(low < high && data[low] <= tem)
//            low++;
//        data[high] = data[low];
//    }
//    data[low] = data[0];
//    return low;
// }
//int quick_sort(int data[], int low, int high)
//{
//    while(low < high)
//    {
//        int mid = Partition(data,low, high);
//        quick_sort(data, low, mid-1);
//        quick_sort(data, mid+1, high);
//    }
//}
//int main()


int Partition(int data[], int low, int high)
{
    int data[0] = data[low];
    int tem = data[low];
    while(low < high)
    {
        while(low < high && data[high] >= tem)
            high--;
        data[low] = data[high];
        while(low < high && data[low] <= tem)
            low++;
        data[high] = data[low];

    }
    data[low] = data[0];
    return low;
}
int quick_sort(int data[], int low, int high)
{
    while(low < high)
    {
        int mid = Partition(data, low, high);
        quick_sort(data, low, mid-1);
        quick_sort(data, mid+1, high);
    }
}
