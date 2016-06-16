#include <stdio.h>

int main()
{
    FILE *p1,*p2;
    int n,a[100];
    p1=fopen("a.txt","r");
    p2=fopen("b.txt","w");

    fscanf(p1,"%d",&n);
    for(int i=0; i<n; i++)
    fscanf(p1,"%d",&a[i]);
     for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    fprintf(p2,"%d ",a[i]);
    fprintf(p2,"\n");


    return 0;
}
