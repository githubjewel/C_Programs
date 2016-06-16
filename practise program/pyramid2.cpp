#include <stdio.h>
#include <math.h>
int a[100][100];
int main()
{
        int n,i,j;

        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            printf("%d ",i);
            a[i][0]+=i+a[i-1][0];
            if(i>1){
            for(j=1; j<i; j++)
            {
                printf("%d ",a[i-1][j-1]);
                a[i][j]=a[i-1][j-1];
                a[i][j]+=a[i-1][j];
            }}
            printf("\n");
            }


    return 0;
}
