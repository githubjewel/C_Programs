#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int s,d,vis[100],child;
int main()
{
int n,m,i,j,g[100][100],par[1000],a,b;
vector< int >V[100];
queue < int > Q;
memset(g,0,sizeof(g));
memset(vis,0,sizeof(vis));
memset(V,0,sizeof(V));
memset(par,0,sizeof(par));
scanf("%d %d",&n,&m);
for(i=0;i<m;i++)
{
scanf("%d %d",&a,&b);
V[a].push_back(b);
g[a][b]=1;
}
scanf("%d",&s);
int count=0,count1=0;
for(i=0;i<n;i++)
{
count+=g[s][i];
count1+=g[i][s];
}
printf("%d %d\n",count,count1);
scanf("%d %d",&s,&d);
Q.push(s);
while(Q.size())
{
int u=Q.front();
Q.pop();
for(i=0;i<V[u].size();i++)
{
int v=V[u][i];
if(vis[v]==0)
{
vis[v]=vis[u]+1;
Q.push(v);
par[v]=u;
}
}
}
printf("%d\n",vis[d]);
child=d;
int t[100];
int child=d;
i=0;
while(1)
{

t[i++]=child;
child=par[child];
if(child==s)
{
t[i++]=child;
break;
}
}
for(j=i-1;j>=0;j--) printf("%d ",t[j]);
return 0;
}
