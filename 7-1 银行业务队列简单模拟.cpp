#include<iostream>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define MAXQSIZE 1001
using namespace std;
typedef int Status;
typedef struct
{
    int *base;
    int first;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &q)
{
    q.base = new int[MAXQSIZE];
    if(!q.base) exit(OVERFLOW);
    q.first = q.rear = 0;
    return OK;
}
Status EnQueue(SqQueue &q, int i)
{
    if((q.rear + 1)%MAXQSIZE == q.first)
        return ERROR;
    q.base[q.rear] = i;
    q.rear = (q.rear + 1)%MAXQSIZE;
    return OK;
}
Status DeQueue(SqQueue &q, int &i)
{
    if(q.first == q.rear)
        return ERROR;
    i = q.base[q.first];
    q.first = (q.first + 1)%MAXQSIZE;
    return OK;
}
bool IsEmpty(SqQueue &q)
{
    if(q.first == q.rear)
        return true;
    return false;
}
int main()
{
    int n,i;
    SqQueue A,B;
    InitQueue(A);
    InitQueue(B);
    cin>>n;
    int tem,e;
    for(i = 0; i < n; i++)
    {
        cin>>tem;
        if(tem%2 == 0)
            EnQueue(B,tem);
        else
            EnQueue(A,tem);
    }
//    for(i = 1; i <= n;)
//    {
//        if(i%3 != 0 && DeQueue(A,e))
//        {
//            if(i = 1)
//            cout<<e;
//            else
//                cout<<" "<<e;
//                i++;
//        }
//        else if(i%3 == 0 && DeQueue(B,e))
//            cout<<e<<" ";
//    }
//    i = 1;
    int flag = 0;
    while(!IsEmpty(A) || !IsEmpty(B))
    {
        if(DeQueue(A,e))
        {
            if(flag == 0)
            {
                cout<<e;
                flag++;
            }
            else
                cout<<" "<<e;

        }
        if(DeQueue(A,e))
        {
            cout<<" "<<e;
        }
        if(DeQueue(B,e))
        {
            if(flag == 0)
            {
                cout<<e;
                flag++;
            }
            else
                cout<<" "<<e;
        }
    }
    return 0;
}
