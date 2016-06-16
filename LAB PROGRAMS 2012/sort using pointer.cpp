#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p,n,a[100],i,temp,j;
   // p=(int*)malloc(n*4);
     p=(int*)malloc(sizeof(int));
    scanf("%d",&n);
    for(i=0; i<n; i++)
    scanf("%d",(p+i));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(*(p+j)>*(p+j+1))
            {
                temp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    printf("%d ",*(p+i));
    return 0;
}
