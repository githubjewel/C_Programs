#include <stdio.h>
int main()
{
    long long n;
    while(scanf("%lld",&n))
    {
        printf("%lld\n",n&3);
    }
    return 0;
}
