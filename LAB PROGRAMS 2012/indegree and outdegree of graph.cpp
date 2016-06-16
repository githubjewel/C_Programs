#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int>edges[100],t;
queue<int>q;
int indegree[100]={0};
int outdegree[100]={0};
int issimple(int n,int s)
{
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0; v<outdegree[u]; v++)
        {
            int k=edges[u][v];
            q.push(k);
            if(k==s) return 1;

        }
    }
    return 0;
}
int main()
{
    int n,e,x,y,v1,v2,rem=0,i;
    scanf("%d %d",&n,&e);
    for(i=0; i<e; i++)
    {
        scanf("%d %d",&x,&y);
        edges[x].push_back(y);
        outdegree[x]++;
        indegree[y]++;

    }
    scanf("%d %d",&v1,&v2);
    printf("indegree of the %d is %d\n",v1,indegree[v1]);
    printf("outdegre of the %d is %d\n",v2,outdegree[v2]);
    for(i=0; i<n; i++)
    {
        sort(edges[i].begin(),edges[i].end());
        for(int j=1; j<outdegree[i]; j++)
        {
            if(edges[i][j]-1==edges[i][j])
            {
                rem=1;
                break;
            }
        }
        if(rem==1) break;

    }
    if(rem==0)
    {
        for(i=0; i<n; i++)
        {
            rem=issimple(n,i);
            if(rem==1) break;
        }
    }
    if(rem==1) printf("It is not a simple graph\n");
    else printf("It is a simple graph\n");
    return 0;


}


