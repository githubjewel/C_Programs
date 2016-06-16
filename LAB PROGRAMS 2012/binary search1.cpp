#include <stdio.h>
int k=0;
int bs(int a[],int n, int item)
{
    int st=0,end=n-1;
    while(1)
    {
        k++;
        int mid=(st+end)/2;
        if(a[mid]==item) return 1;
        if(st>end) return 0;
        if(a[mid]>item)
        end=mid-1;
        if(a[mid]<item)
        st=mid+1;
    }
}

int main()
{
    int n,a[100],i,j,item;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    scanf("%d",&a[i]);
    scanf("%d",&item);
    if(bs(a,n,item))
    printf("FOUND\n");
    else
    printf("NO\n");
    printf("%d\n",k);
    return 0;
}
