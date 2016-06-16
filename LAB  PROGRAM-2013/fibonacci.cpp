#include <stdio.h>
#include <math.h>
unsigned long k;
unsigned long fibonacci(unsigned long n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);

}
void sum(unsigned long p)
{

   unsigned long s=fibonacci(k);

    printf("%lu ",s);

    if(k==p)
    {
        printf("\n");
        return;
    }

    k=k+1;
    sum(p);



}
int main()
{
    unsigned long s;

    while(1)
    {
         k=0;

        printf("please insert a number:\n");

        scanf("%ul",&s);

        sum(s);



    }
    return 0;
}
