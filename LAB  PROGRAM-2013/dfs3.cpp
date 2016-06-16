#include <stdio.h>
#include <vector>
#define white 1
#define gray 2
#define black 3
using namespace std;
vector<int>G[100];
int par[100], color[100], ftime[100], dtime[100],time;
void dfs_visit(int u)
{
    color[u]=gray;
   // printf("reached %d\n",u);
    time++;
    dtime[u]=time;
     //printf("reached %d\n",u);
    int i;
    for(i=0;i<G[u].size();i++)
    {
       // printf("reached1  \n");
        int v = G[u][i];

        if(color[v]==white)
        {
            par[v]=u;
            dfs_visit(v);
        }
    }
    color[u]=black;
    ftime[u]=time;

}
void dfs(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        color[i]=white;
        par[i]=-1;
    }

    time=0;
    for(i=1;i<=n;i++)
    {
        if(color[i]==white)
        {
            dfs_visit(i);
        }
    }
}

int main()
{
    int n, r;
    scanf("%d %d",&n, &r);
    int i;
    for(i=0;i<r;i++)
    {
        int x, y;
        scanf("%d %d",&x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(n);
    for(i=1;i<=n;i++)
    {
        printf("Node %d: \n\tparent = %d\n\tdiscovery time = %d\n\tfinish time = %d\n",i,par[i],dtime[i],ftime[i]);
    }
    return 0;
}
