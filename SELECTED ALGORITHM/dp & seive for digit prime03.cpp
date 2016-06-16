#include <iostream>
#include <cstdio>
using namespace std;

int b[1000000]={0};
void prime()
{
int i,j;
b[0]=1;
b[1]=1;
for(i=1;i<1000;i++)
if (b[i]==0)
for(j=2;j<=1000000/i;j++)
b[i*j]=1;
}


int main()
{
prime();
long i;
int dp[1000000]={0};
int df[1000000]={0};
int dcnt=0;

long temp;
long t;
for(i=0;i<1000000;i++)
{
if(b[i]==1)
dp[i]=dcnt;
else
{
t=i;
temp=t%10;
t/=10;
while(t!=0)
{
temp+=t%10;
t/=10;
}
if(b[temp]==0)
{
dp[i]=++dcnt;
df[i]=1;
}
else
dp[i]=dcnt;
}

}

int n;
cin>>n;
long u,v,ch;
while(n--)
{
cin>>u>>v;
if(u>v)
{
ch=u;
u=v;
v=ch;
}
if(df[u]==1&&df[v]==1)
cout<<dp[v]-dp[u]+1<<endl;
else if((df[u]==1&&df[v]!=1)||(df[u]!=1&&df[v]==1))
cout<<dp[v]-dp[u]+1<<endl;
else
cout<<dp[v]-dp[u]<<endl;
}
return 0;
}
