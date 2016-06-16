#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)){
    n=(n<<3)+2*n;
    printf("%d\n",n);
    }
    return 0;
}
