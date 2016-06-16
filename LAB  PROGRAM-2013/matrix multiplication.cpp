#include<stdio.h>
int main()
{
    int a[10][20],b[10][20],c[100][200],n1,n2,m1,m2,m3,m4,i,j,k,sum;
    FILE*fp;
    fp=fopen("matrix.txt","r");
    fscanf(fp,"%d %d",&m1,&m2);
    for(i=0;i<m1;i++)
    {
     for(j=0;j<m2;j++)
     {
         fscanf(fp,"%d",&a[i][j]);
     }
    }
     fscanf(fp,"%d %d",&m3,&m4);
    for(i=0;i<m3;i++)
    {
     for(j=0;j<m4;j++)
     {
         fscanf(fp,"%d",&b[i][j]);
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
             printf("\n");
         }

     }

return 0;
}


