#include <stdio.h>
#include <string.h>
int main()
{
    while(1)
    {
        int n,i,j,k,m;
        scanf("%d",&n);
        for(i=1; i<=n/2+1; i++)
        {
            m=(n/2)+1;
           for(j=1; j<=m-i; j++)  //FOR LOOP ER CONDITIO DILE AR EK ROKOM HOBE
           printf(" ");
           for(k=1; k<=i; k++)
           printf("%d ",i);
           printf("\n");
        }
        for(i=m+1; i<=n; i++)
        {
            for(j=1; j<=i-m; j++)
            printf(" ");
            for(k=1; k<=n-i+1; k++)
            printf("%d ",n-i+1);
            printf("\n");
        }

    }
    return 0;
}
