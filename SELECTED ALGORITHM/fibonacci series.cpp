#include <stdio.h>
#include <string.h>
#define limit 5001
#define len 1050
int fibo[limit][len];
void fibonacci()
{
    long int i,j;
    fibo[0][0]=0;
    fibo[1][0]=1;
    fibo[2][0]=1;
    for(i=3; i<limit; i++)
    {
        for(j=0; j<len; j++)
        {
            fibo[i][j]+=fibo[i-1][j]+fibo[i-2][j];
            if(fibo[i][j]>=10)
            {
                fibo[i][j+1]+=fibo[i][j]/10;
                fibo[i][j]=fibo[i][j]%10;
            }
        }
    }
}
int main()
{
    fibonacci();
    long int n,i;
    while(scanf("%ld",&n)==1)
    {

        for(i=len-1; i>0; i--)
        {
            if(fibo[n][i]!=0) break;
        }
        for(; i>=0; i--)
        printf("%d",fibo[n][i]);
        printf("\n");
    }

}
