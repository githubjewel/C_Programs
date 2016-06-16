#include <stdio.h>
#include <math.h>
#include <mem.h>
int main()
{
    int n,i,j,a[10000],b[10000];
    scanf("%d",&n);
    memset(b, 0, sizeof(b));
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        b[a[i]]++;

    }
    for(i=0; i<n-1; i++)
    {
        if(b[a[i]]>b[a[i+1]])
        a[i+1]=a[i];
        if(b[a[i]]==b[a[i+1]])
        {
            if(a[i]<a[i+1])
            a[i+1]=a[i];
        }
    }
    printf("%d\n",a[n-1]);
    return 0;
}
