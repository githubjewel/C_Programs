#include<stdio.h>
#include<vector>
#define white 0
#define gray 1
#define black 2
int time = 0 ;
int cycle  = 0 ;
using namespace std ;
vector<int>graph[100] ;
vector<int>topsort ;
int cal[100] , par[100] , d[100] , f[100] ;
int v ;
void dfs(int u)
{
	int j ;
	cal[u] = 1 ;
	time = time+1 ;
	d[u] = time ;
	for(j = 0 ; j < graph[u].size() ; j++)
	{
		v = graph[u][j] ;
		if(cal[v] == white)
		{
			//printf("%d\n" , u);
			par[v] = u ;
			dfs(v) ;
		}
		if(cal[v] == gray )
		{
            cycle = 1 ;
		}
	}
	cal[u] = black ;
	time = time+1;
	f[u] = time ;
	topsort.push_back(u) ;
}
int main()
{
	int  u ;
	bool flag = true ;
	int j ;
	int n , i , a , b , e ;
	int source ;
	int node[100] ;
	for(i = 0 ; i < 100 ; i++)
		cal[i] = par[i] = 0;
	printf("node : ");
	scanf("%d",&n) ;
	printf("Edge : ");
	scanf("%d",&e) ;
	for(i = 0 ; i < e ; i++)
	{
		scanf("%d %d",&a,&b) ;
		graph[a].push_back(b) ;
		//graph[b].push_back(a) ;
		node[i] = a ;

	}
	printf("Source : ") ;
	scanf("%d",&source) ;
		u = source ;
		if(cal[u] == 0)
			dfs(u) ;
    for(i = 1 ; i <= n ; i++)
    {
        u = i ;
        if(u == source)
            continue ;
        if(cal[u] == 0)
            dfs(u) ;
    }

	for(i = 1 ; i <= n ; i++)
	{
		printf("%d -> %d\ndis_time : %d\nFinish time : %d\n",i , par[i] , d[i] , f[i]) ;
	}
	if(cycle == 1)
        printf("Cycle found : Topological sort is not possible\n") ;
        else
        {
            printf("Topological sort : ") ;
            for(i = topsort.size()-1 ; i >= 0 ; i--)
                printf("%d " , topsort[i]) ;
                printf("\n") ;
        }
	return 0 ;
}
