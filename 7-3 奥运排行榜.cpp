#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct Nation
{
    int id;
    int gold;
    int medal;
    int avggold;
    int avgmedal;
};
typedef struct Gold
{
    int id;
    int goldnum;
};
typedef struct Medal
{
    int id;
    int medalnum;
};
typedef struct Avggold
{
    int id;
    double avggoldnum;
};
typedef struct Avgmedal
{
    int id;
    double avgmedalnum;
};
int main()
{
    int N,M,i,j,tempopulation,nationid;
    scanf("%d %d",&N,&M);
    Nation nations[N+1];
    Gold gold[N+1];
    Medal medal[N+1];
    Avggold avggold[N+1];
    Avgmedal avgmedal[N+1];
    for(i = 0; i < N; i++)
    {
        nations[i].id = i;
        gold[i].id = i;
        cin>>gold[i].goldnum;
        medal[i].id = i;
        cin>>medal[i].medalnum;
        avggold[i].id = i;
        avgmedal[i].id = i;
        cin>>tempopulation;
        avggold[i].avggoldnum = 1.0*gold[i].goldnum/tempopulation;
        avgmedal[i].avgmedalnum = 1.0*medal[i].medalnum/tempopulation;
    }

    //对金牌进行排名，冒泡排序
    Gold temgold;
    for(i = 1; i < N; i++)
        for(j = 0; j < N-i; j++)
        {
            if(gold[j].goldnum < gold[j+1].goldnum)
            {
                temgold = gold[j];
                gold[j] = gold[j+1];
                gold[j+1] = temgold;
            }
        }
    //设置国家的金牌名次
    for(i = 0; i < N; i++)
    {
        //下标即名次，奖牌数相同的并列
        if(i > 0 && gold[i].goldnum == gold[i-1].goldnum)
            nations[gold[i].id].gold = nations[gold[i-1].id].gold;
        else
            nations[gold[i].id].gold = i+1;
    }

    //对奖牌榜进行排名
    Medal temmedal;
    for(i = 1; i < N; i++)
        for(j = 0; j < N-i; j++)
        {
            if(medal[j].medalnum < medal[j+1].medalnum)
            {
                temmedal = medal[j];
                medal[j] = medal[j+1];
                medal[j+1] = temmedal;
            }
        }
    //设置国家的奖牌名次
    for(i = 0; i < N; i++)
    {
        if(i > 0 && medal[i].medalnum == medal[i-1].medalnum)
            nations[medal[i].id].medal = nations[medal[i-1].id].medal;
        else
        nations[medal[i].id].medal = i+1;
    }


    //对人均金牌榜排名
    Avggold temavggold;
    for(i = 1; i < N; i++)
        for(j = 0; j < N-i; j++)
        {
            if(avggold[j].avggoldnum < avggold[j+1].avggoldnum)
            {
                temavggold = avggold[j];
                avggold[j] = avggold[j+1];
                avggold[j+1] = temavggold;
            }
        }
    //设置国家的人均金牌名次
    for(i = 0; i < N; i++)
    {
        if(i > 0 && avggold[i].avggoldnum == avggold[i-1].avggoldnum)
            nations[avggold[i].id].avggold = nations[avggold[i-1].id].avggold;
        else
            nations[avggold[i].id].avggold = i+1;
    }


    //对人均奖牌榜排名
    Avgmedal temavgmedal;
    for(i = 1; i < N; i++)
        for(j = 0; j < N-i; j++)
        {
            if(avgmedal[j].avgmedalnum < avgmedal[j+1].avgmedalnum)
            {
                temavgmedal = avgmedal[j];
                avgmedal[j] = avgmedal[j+1];
                avgmedal[j+1] = temavgmedal;
            }
        }

    //设置国家人均奖牌名次
    for(int i = 0; i < N; i++)
    {
        if(i > 0 && avgmedal[i].avgmedalnum == avgmedal[i-1].avgmedalnum)
            nations[avgmedal[i].id].avgmedal = nations[avgmedal[i-1].id].avgmedal;
        else
            nations[avgmedal[i].id].avgmedal = i+1;
    }


//    for(i = 0; i < N; i++)
//    {
//        cout<<"ID:"<<i<<" Gold:"<<nations[i].gold<<" Medal:"<<nations[i].medal<<" Avggold:"<<nations[i].avggold<<" Avgmedal:"<<nations[i].avgmedal<<endl;
//    }
    for(i = 0; i < M; i++)
    {
        int num = 0;
        int high = N;
        cin>>nationid;
        if(nations[nationid].gold < high)
        {
            high = nations[nationid].gold;
            num = 1;
        }

        if(nations[nationid].medal < high)
        {
            high = nations[nationid].medal;
            num = 2;
        }
        if(nations[nationid].avggold < high)
        {
            high = nations[nationid].avggold;
            num = 3;
        }

        if(nations[nationid].avgmedal < high)
        {
            high = nations[nationid].avgmedal;
            num = 4;
        }
        if(i != 0)
            cout<<" ";
        cout<<high<<":"<<num;

    }
    return 0;
}
