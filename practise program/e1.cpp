#include <stdio.h>
int main()
{
    int a,b,*c,*d;
    a=10;b=20;
    c=&a;
    d=&b;
    printf("%d %d %d %d\n",a,b,*c,*d);
    *c=*d;
    printf("%d %d %d %d",a,b,*c,*d);
    c=d;

    printf("%d %d %d %d",a,b,*c,*d);
    return 0;

}
