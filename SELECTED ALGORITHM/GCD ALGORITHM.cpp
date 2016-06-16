#include <stdio.h>
#include <string.h>
#include <math.h>
int gcd(int a,int b)
{
    if(a%b==0)
              return b;
          gcd(b,a%b);

}
int main()
{
    int a,b,c;
    while (1){scanf("%d %d",&a,&b);
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    c=gcd(a,b);
    printf("%d\n",c);

    }return 0;
}
