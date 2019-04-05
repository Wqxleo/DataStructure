#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N )
{
    int i,j;
    ElementType tem;
    for(i = 1; i < N; i++)
    {
        for(j = 0; j < N-i;j++)
        {
            if(A[j] > A[j+1])
            {
                tem = A[j];
                A[j] = A[j+1];
                A[j+1] = tem;
            }
        }
    }
    if(N%2 == 0)
    {
        return (A[N/2-1]+A[N/2])/2.0;
    }
    else
    return A[N/2];
}

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}
