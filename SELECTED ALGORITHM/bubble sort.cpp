#include <stdio.h>
#include <math.h>
void bubble(int a[],int n)
{
    int i,j,temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=tem;
            }
        }
    }
}
int main()
{
    bubble();
    return 0;
}
