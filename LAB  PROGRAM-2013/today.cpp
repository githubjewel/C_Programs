#include<stdio.h>
#include <math.h>
#include <algorithm>
#include<vector>
#define  W 0
#define Gray 1
#define B 2
using namespace std;

int global_time = 0;

bool is_cycle=true;

vector<int>G[100];

vector<int>top_value ;

long set_color[500],set_parent[500],discover[500],finish[500],vertex;



void dfs_graph(long node)
{


    set_color[node] = Gray;

    global_time+=1;

    discover[node] = global_time;

    for(int x = 0 ; x < G[node].size() ; x++)
    {
        vertex= G[node][x];

        if(set_color[vertex] == W)
        {
            set_parent[vertex] = node;

            dfs_graph(vertex);
        }
        if(set_color[vertex] == Gray )
		{
            is_cycle = false ;
		}
    }
    set_color[node] = B;

    global_time+=1;

    finish[node] = global_time;

    top_value.push_back(node);
}
int main()
{
    long number_of_edge,given_source,number_of_node,x,y,a[500],s=500,k;

    int choice;

	for(int v=0; v<500; v++)
	{
	    set_color[v] = W;

	    set_parent[v] = 0;
	}

	printf("Please select from the menu: \n");

	while(1){

    printf("1.For create graph\n2.For Traverse\n3.Ror sort\n");

  scanf("%d",&choice);

    if(choice==1)
    {

	      printf("Enter no of nodes : \n");

	        scanf("%d",&number_of_node) ;

	        printf("Enter no of edges: \n");

            scanf("%d",&number_of_edge);

            printf("\n");

            printf("Enter the connectd edges:\n");

	for(int v = 0 ; v < number_of_edge ; v++)
	{
		scanf("%d %d",&x,&y) ;

		G[x].push_back(y) ;

		a[v] = x ;

	}
	printf("Enter the source :\n");

	scanf("%d",&s);

    int node= s;

    if(set_color[node] == W)

        dfs_graph(node) ;

    for(int v = 1 ; v <= number_of_node ; v++)

       {

        k = v ;

        if(k == s)

            continue ;

        if(set_color[k] == W)

            dfs_graph(k) ;
    }
    }

    if(choice==2)
    {
    for(int v = 1 ; v <= number_of_node ; v++)
	{
		printf("For %d \n",v);

		printf("The parent is:= %d\n",set_parent[v]);


		printf("The discover time is:= %d\n",discover[v]);


		printf("The finishing time is:= %d\n",finish[v]);


	}

    }
    if(choice==3){

	if(is_cycle== false)

        printf("There is cycle\n") ;
        else
        {
            for(int v = top_value.size()-1 ; v >= 0 ; v--)

                printf("%d " , top_value[v]) ;

                printf("\n") ;
        }
    }
	}
    return 0;
}


