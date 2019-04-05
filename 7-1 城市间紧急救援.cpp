#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, s,q;//城市数，道路数，出发城市，目的城市
int b[600];
int a[600][600];//地图矩阵
int c[600];//记录最短路径
int pre[600];
int inf;//最大距离
int sx[600];
int toval[600];//记录总的救援队数量
int main()
{
    memset(a, 0, sizeof(0));
    int pathnum[600];//走过的路径数
    inf=99999999;
    scanf("%d%d%d%d", &n, &m, &s, &q);
    int i;
    int j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(i==j)a[i][j]=0;
            else a[i][j]=inf;
        }
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
    for(i=0; i<m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(z<a[x][y])
            a[x][y]=a[y][x]=z;
    }
    int vis[600];//标记是否访问过


    //初始化
    for(i=0; i<n; i++)
    {
        vis[i]=0;
        c[i]=inf;
        toval[i]=0;
    }
    int k;
    c[s]=0;
    vis[s]=1;//出发城市标记访问
    pathnum[s]=1;
    toval[s]=b[s];//总的救援队数量等于出发城市的救援队数量


    {
        for(i=0; i<n; i++)
        {
            int mini, minn;
            mini=s;//前一个城市的下标
            minn=inf;//初始化一个最小距离，设置为最大值
            for(j=0; j<n; j++)
            {
                //对城市遍历，如果没有访问过，而且最小值大于城市的
                if(vis[j]==0 && minn>c[j])
                {
                    mini=j;
                    minn=c[j];
//                    cout<<"第一次循环 mini:"<<mini<<"minn:"<<minn<<endl;
                }
            }
            vis[mini]=1;
            for(j=0; j<n; j++)
            {
                if(vis[j]==0)
                    if(c[mini]+a[mini][j]<c[j])
                    {
                        c[j]=c[mini]+a[mini][j];
                        pre[j]=mini;
                        toval[j]=b[j]+toval[mini];
                        pathnum[j]=pathnum[mini];
                    }
                    else if(c[mini]+a[mini][j]==c[j] )
                    {
                        if( toval[j]<b[j]+toval[mini])
                        {
                            toval[j]=b[j]+toval[mini];
                            pre[j]=mini;
                        }
                        pathnum[j]+=pathnum[mini];
                    }
            }
        }
    }
    int top=0;
    j=q;
    while(j!=s)
    {
        sx[top++]=j;
        j=pre[j];
    }
    sx[top]=j;
    printf("%d %d\n", pathnum[q], toval[q]);
    for(; top>=0; top--)
    {
        printf("%d", sx[top]);
        if(top!=0)printf(" ");
    }
    return 0;
}
