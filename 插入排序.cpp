//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int arr[], n)
{
    int i,j;
    for(i = 2; i <= n; i++)
    {
        if(arrr[i] < arr[i-1])
        {
            arr[0] = arr[i];
            arr[i] = arr[i-1];
            for(j = i-2; arr[0] < arr[j];--j)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = arr[0];
        }

    }
}

//’€∞Î≤Â»Î≈≈–Ú
void BInsertSort(int arr[], int n)
{
    int i,j,low,high,mid;
    for(i = 2; i < n; ++i)
    {
        arr[0] = arr[i];
        low = 1;
        high = i-1;
        while(low < high)
        {
            mid = (low+high)/2;
            if(arr[0] < arr[m])
                high = m-1;
            else
                low = m+1;

        }
        for(j = i-1; j > high+1; --j)
            arr[j+1] = arr[j];
        arr[high] = arrr[0];

    }
}

//œ£∂˚≈≈–Ú
void ShellInsertSort(int arr[], int n)
{

}
