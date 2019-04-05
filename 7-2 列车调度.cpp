#include<iostream>
#include<malloc.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
using namespace std;

int main()
{
    int n,i,j;
    int *arr;
    cin>>n;
    arr = new int[n];
    int tem,num,flag;
    num  = 1;
    arr[0] = n+1;
    for(i = 0; i < n; i++)
    {
        cin>>tem;
        flag = 0;
        int low = 0;
        int high = num-1;
        while(low <= high)
        {
            int middle = (high - low)/2 + low;
            if(tem < arr[middle])
            {
                if(middle == 0)
                {
                    arr[middle] = tem;
                    flag = 1;
                    break;
                }
                else if(tem < arr[middle-1])
                {
                    high = middle - 1;
                }
                else if(tem > arr[middle-1])
                {
                    arr[middle] = tem;
                    flag = 1;
                    break;
                }

            }
            else if(tem > arr[middle])
            {
                low = middle +1;
            }
//            cout<<"tem:"<<tem<<endl;
//            cout<<low<<" "<<high<<endl;
        }
        if(flag == 0)
        {
            arr[num] = tem;
//            cout<<arr[num]<<endl;
            num++;
        }
//        flag = 0;
//        for(j = 0; j < num; j++)
//        {
//
//            if(tem < arr[j])
//            {
//                arr[j] = tem;
//                flag = 1;
//                break;
//            }
//            else if(tem > arr[num-1])
//                break;
//        }
//        if(flag == 0)
//        {
//
//            arr[num] = tem;
//            num++;
//        }
    }
    delete []arr;
    cout<<num;
}
