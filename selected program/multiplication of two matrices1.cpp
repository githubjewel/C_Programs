#include <stdio.h>
#include <math.h>
int a[100][100],b[100][100],c[100][100];
int main()
{
    int r1,c1,r2,c2,i,j,sum,k;
    scanf("%d %d",&r1,&c1);
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        scanf("%d",&a[i][j]);
    }

    scanf("%d %d",&r2,&c2);
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        scanf("%d",&b[i][j]);
    }
    printf("the multiplication of the matrices is:\n\n\t");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            //sum=0;
            c[i][j]=0;
            for(k=0; k<c1; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];

            }
            printf("%d\t",c[i][j]);
        }
        printf("\n\t");
    }
    return 0;
}
