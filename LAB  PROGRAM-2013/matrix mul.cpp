#include<stdio.h>
int main()
{
    int a[10][20],b[10][20],c[100][200],m1,m2,m3,m4,i,j,k,sum;

    scanf("%d %d",&m1,&m2);
    for(i=0;i<m1;i++)
    {
     for(j=0;j<m2;j++)
     {
         scanf("%d",&a[i][j]);
     }
    }
     scanf("%d %d",&m3,&m4);
    for(i=0;i<m3;i++)
    {
     for(j=0;j<m4;j++)
     {
         scanf("%d",&b[i][j]);
     }
    }
     if(m2!=m3)
     {
         printf("invalid");
     }
     else
     {
         for(i=0;i<m1;i++)
         {
             for(j=0;j<m4;j++)
             {
                 sum=0;
                 for(k=0;k<m3;k++)
                 {
                     sum=sum+a[i][k]*b[k][j];
                 }
                  c[i][j]=sum;
                  sum=0;

             }
         }

         for(i=0;i<m1;i++)
         {
             for(j=0;j<m4;j++)
             printf("%d ",c[i][j]);
             printf("\t");
         }
         printf("\n");
     }

return 0;
}

