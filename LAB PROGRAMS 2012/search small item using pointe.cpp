#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p,i,j,n,x;
    p=(int*)malloc(sizeof(int));
    scanf("%d",&n);
    for(i=0; i<n; i++)
    scanf("%d",(p+i));
    x=*p;
    for(i=1; i<n; i++)
    {
        if(*(p+i)<x)
        x=*(p+i);

    }
    printf("%d\n",x);
    return 0;
}
