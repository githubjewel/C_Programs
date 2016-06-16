#include <stdio.h>
#include <math.h>
long long factorial(long long  n)
{

    if(n==0||n==1) return 1;
    return (n*factorial(n-1));


}
int main()
{
     long long n,sum;

     while(1)
    {
        printf("please insert a number:\n");
        scanf("%lld",&n);
        if(n<0)
        printf("undefined\n");
        else{
        sum=factorial(n);
        printf("The factorial of the number is: %lld\n\n",sum);}

    }
}
