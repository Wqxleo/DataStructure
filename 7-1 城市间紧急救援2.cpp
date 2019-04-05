#include <stdio.h>
#include <string.h>
#define INF 999999
int n, m, s, d, vis[505], l[505][505], dis[505], p[505], sum[505], ans[505];
void dfs(int length, int people, int dd)
{
    int i;
    if(dd == s)
        return;
    for(i = 0 ; i < n ; i++)
    {
        if(length - l[dd][i] == dis[i] && people - p[dd] == sum[i])
        {
            dfs(dis[i], sum[i], i);
            printf("%d ", i);
            break;
        }
    }
}
void dij()
{
    int i, j, k, min;
    vis[s] = 1;
    sum[s] = p[s];
    ans[s] = 1;
    for(i = 0 ; i < n ; i++)
    {
        dis[i] = l[s][i];
        if(s != i && l[s][i] != INF)
        {
            sum[i] = p[i] + p[s];
            ans[i] = 1;//
        }
    }
    for(i = 0 ; i < n-1 ; i++)
    {
        min = INF;
        for(j = 0 ; j < n ; j++)
        {
            if(!vis[j] && min > dis[j])
            {
                min = dis[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(j = 0 ; j < n; j++)
        {
            if(!vis[j])
            {
                if(dis[j] > dis[k] + l[k][j])
                {
                    dis[j] = dis[k] + l[k][j];
                    sum[j] = sum[k] + p[j];
                    ans[j] = ans[k];//
                }
                else if(dis[j] == dis[k] + l[k][j])
                {
                    ans[j] += ans[k];//
                    if(sum[j] < sum[k] + p[j])
                    {
                        sum[j] = sum[k] + p[j];
                    }
                }
            }
        }
    }
}
int main()
{
    int i, j, x, y, ll;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for(i = 0 ; i < n ; i++)
        for(j = 0 ; j < n ; j++)
        {
            l[i][j] = INF;
        }
    for(i = 0 ; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for(i = 0 ; i < m ; i++)
    {
        scanf("%d %d %d", &x, &y, &ll);
        l[x][y] = l[y][x] = ll;
    }
    if(n == 1)
    {
        printf("1 %d\n1", p[0]);
        return 0;
    }
    dij();
    printf("%d %d\n", ans[d], sum[d]);
    printf("%d ", s);
    dfs(dis[d], sum[d], d);
    printf("%d", d);
    return 0;
}
