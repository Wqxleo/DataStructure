#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

typedef struct{
	int b,next,v;
}node;
node p[10001];
int st[10001];
int earliest[1001];int latest[1001];
int rudu[1001];int chudu[1001];
int n;
void init()
{
	memset(st,-1,sizeof(st));
	memset(earliest,0,sizeof(earliest));
	memset(rudu,0,sizeof(rudu));
	memset(chudu,0,sizeof(chudu));
}
stack<int>s;
bool rstack()
{
	int i,j;
	for (i=1;i<=n;i++)
		if (rudu[i]==0)
			break;
	if (i==n+1) return false;
	s.push(i);
	rudu[i]=-1;
	for (j=st[i];j!=-1;j=p[j].next){
		rudu[p[j].b]--;
	}
	return true;
}
bool keyroad()
{
	while (!s.empty()) s.pop();
	for  (int t=0;t<n;t++)
	{
		if (!rstack()) return false;
		int head=s.top();
		for (int i=st[head];i!=-1;i=p[i].next)
		{
			int k=p[i].b;
			earliest[k]=max(earliest[k],earliest[head]+p[i].v);
		}
	}
	int themax=0;int pos;
	for (int i=1;i<=n;i++)
		if (earliest[i]>themax&&chudu[i]==0)
		{
			themax=earliest[i];pos=i;
		}
	for (int i=1;i<=n;i++)
		latest[i]=99999999;
	latest[pos]=themax;
	printf("%d\n",themax);
	while (!s.empty()){
		int head=s.top();
		s.pop();
		for (int i=st[head];i!=-1;i=p[i].next)
		{
			int k=p[i].b;
			latest[head]=min(latest[head],latest[k]-p[i].v);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=st[i];j!=-1;j=p[j].next)
		{
			int a=earliest[i];
			int b=latest[p[j].b]-p[j].v;
			if (a==b)
				printf("%d->%d\n",i,p[j].b);
		}
	}
	return true;
}
int main()
{
	int m,i,j,x,y,z;
	scanf("%d%d",&n,&m);
	init();
	for (i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		p[i].b=y;
		p[i].next=st[x];
		p[i].v=z;
		st[x]=i;
		rudu[y]++;
		chudu[x]++;
	}
	bool f=keyroad();
	if (!f) printf("0\n");
}
