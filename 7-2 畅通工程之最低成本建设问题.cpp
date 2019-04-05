#include<bits/stdc++.h>
#define MAX 0x3f3f3f;
using namespace std;

int Map[1050][1050];
int dis[1050];
int vis[1050];

int Prim (int n);

int main()
 {
  int n, m;
  int i, j;
  int a, b, c;
  while (cin >> n >> m)
    {
      memset(vis, 0, sizeof(vis));
       for (i = 1;i <= n;i ++)
        {
          for (j = 1;j <= n;j ++)
             {
                if (i == j)
                   Map[i][j] = 0;
                else
                   Map[i][j] = MAX;
             }
        }
        for (i = 1;i <= m;i ++)
           {
             cin >> a >> b >> c;
             if (Map[a][b] > c)
                {
                  Map[a][b] = Map[b][a] = c;
                }
           }
        int ans = Prim(n);
        if (ans == 4144966)
        cout << "Impossible" << endl;
        else
        cout << ans << endl;
    }
 return 0;
 }

 int Prim (int n)
  {
    int i, j, t;
    int sum = 0;
    vis[0] = 1;
    for (i = 1;i <= n;i ++)
       {
         for (j = 1;j <= n;j ++)
             {
                dis[i] = Map[i][j];
             }
       }
    for (i = 1;i <= n;i ++)
       {
          t = i;
          int MIN = MAX;
          for (j = 1;j <= n;j ++)
              {
                 if (MIN > dis[j] && !vis[j])
                      {
                        MIN = dis[j];
                        t = j;
                      }

              }
         sum = sum + MIN;
         vis[t] = 1;
         for (j = 1;j <= n;j ++)
            {
                if (Map[t][j] < dis[j]&&!vis[j])
                   {
                      dis[j] = Map[t][j];
                    }
            }
       }
     return sum;
  }
