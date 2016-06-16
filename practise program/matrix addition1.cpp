#include <stdio.h>
#include <math.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],c1,c2,c3,c4;
    int i,j;
    scanf("%d %d",&c1,&c2);
    for(i=0; i<c1; i++)
    {
        for(j=0; j<c2; j++)
        scanf("%d",&a[i][j]);
    }
    scanf("%d %d",&c3,&c4);
    for(i=0; i<c3; i++)
    {
        for(j=0; j<c4; j++)
        scanf("%d",&b[i][j]);
    }
    if(c1!=c3)
    return 0;
    printf("the sum of the matrices is:\n\n\t\t");
    for(i=0; i<c1; i++)
    {
        for(j=0; j<c3; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n\t\t");
    }


    return 0;
}
