#include <stdio.h>
int main()
{
    int a[100][100],i,j,n,s=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        if(i>0)
        s+=a[i-1][i];
    }
    printf("%d",s);
    return 0;
}
