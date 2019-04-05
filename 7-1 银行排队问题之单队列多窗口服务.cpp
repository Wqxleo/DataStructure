#include<iostream>
#include<malloc.h>
#include<iomanip>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define MAXQSIZE 1001
using namespace std;
typedef int Status;
int main()
{
    int n,m;
    cin>>n;
    int t1,t2,i,j;
    int waittime,maxwt,sumwait,finishtime;
    waittime = maxwt = sumwait = finishtime= 0;
    int CurrentTime = 0;//现在的时间
    int arr[n][2];
    //把到达时间和处理时间存在二维数组里
    for(i = 0; i < n; i++)
    {
        cin>>t1>>t2;
        if(t2 > 60)
            t2 = 60;
        arr[i][0] = t1;
        arr[i][1] = t2;
    }
    cin>>m;
    int w1[m],w2[m];//分别记录每个窗口处理完到的时间的接待的客户人数
    for(i = 0; i < m; i++)
    {
        //赋0
        w1[i] = w2[i] = 0;
    }
    CurrentTime = 0;
    for(i = 0; i < n; i++)
    {
        int flag = 0;
        for(j = 0; j < m; j++)
        {
            //客户到达时间大于窗口处理时间
            if(w1[j] <= arr[i][0])
            {
                flag = 1;
                //更新现在时间
                CurrentTime = arr[i][0];
                //更新窗口处理时间
                w1[j] = CurrentTime + arr[i][1];
                //处理人数加1
                w2[j]++;
                break;
            }
        }

        CurrentTime = arr[i][0];
        //客户到达时间小于处理时间，需要等待
        if(flag == 0)
        {
            //保存最小处理时间的窗口
            int mint = w1[0];
            int tem = 0;
            for(j = 1; j < m; j++)
            {
                if(mint > w1[j])
                {
                    mint = w1[j];
                    tem = j;
                }
            }
            //对用时最少的窗口进行操作
            waittime = w1[tem] - arr[i][0];
            if(maxwt < waittime)
                maxwt = waittime;
            sumwait += waittime;
            cout<<"sumwait:"<<sumwait<<endl;
            w1[tem] += arr[i][1];
            w2[tem]++;
        }
    }
    //获取完成时间
    for(i = 0; i < m; i++)
    {
        if(finishtime < w1[i])
            finishtime=w1[i];
    }
    double avg;
    avg = sumwait*1.0/n;
    cout << setiosflags(ios::fixed)<< setprecision(1)<<avg<<" ";
    cout<<maxwt<<" ";
    cout<<finishtime<<endl;
    for(i =  0; i < m; i++)
    {
        if(i == 0)
            cout<<w2[i];
        else
            cout<<" "<<w2[i];
    }
    return 0;
}
