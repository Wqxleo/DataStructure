#include <iostream>
using namespace std;
int main()
{
    int N,K,i,j,tem;
    cin>>N>>K;
    int arr[N];
    for(i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    for(i = 1; i < N; i++)
    {

        for(j = 0; j < N-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                tem = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tem;
            }
        }
        if(i == K)
            break;
    }
    cout<<arr[0];
    for(i = 1; i < N; i++)
    {
        cout<<" "<<arr[i];
    }
    return 0;
}
