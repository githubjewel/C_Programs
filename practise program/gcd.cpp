#include <stdio.h>
#include <math.h>
int gcd(int a,int b)
{
    if(a%b==0) return b;
    gcd(b,a%b);
}
int main()
{
    int a,b;
    while(EOF)
    {
        scanf("%d %d",&a,&b);
        printf("GCD=%d\n",gcd(a,b));
        printf("LCM=%d\n",(a*b)/gcd(a,b));
    }
    return 0;
}
