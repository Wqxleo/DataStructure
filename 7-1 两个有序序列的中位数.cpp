#include <iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    cin>>n;
    int arr1[n];
    int arr2[n];
    int arr3[2*n];
    for(i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    for(i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
    i = j = k = 0;
    while(i < n && j < n)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while(i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while(j < n)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
    for(i = 0; i < 2*n; i++)
        cout<<arr3[i]<<" ";
    cout<<endl;
    cout<<arr3[(2*n-1)/2];

}
