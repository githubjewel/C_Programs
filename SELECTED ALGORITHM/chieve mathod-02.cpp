#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdio>
using namespace std;
/*int b[1000000]={0};
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
*/

int a[1000000];
void chiv()
{
    int i,j;
    memset(a, 0, sizeof(a));
    a[0]=a[1]=1;
    for(i=2; i<1000; i++)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<1000000; j+=i)
            {
                a[j]=1;
            }
        }
    }
}


/*#define max 1000009
long seive[max];
void genseive()
{
int i,j;
int sq=sqrt(max);
seive[0]=seive[1]=1;
for(i=2;i<=sq;i++)
{
for(j=i+i;j<max;j+=i)
seive[j]=1;
}

}*/


int main()
{
   /* prime();*/
   chiv();
  int sum=0;
    for(int i=0; i<=100; i++)
    {
        if(a[i]==0)  sum++;

    }
            printf("%d\n",sum);
}
