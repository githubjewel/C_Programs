// Prime generation with sieve of eratosthenes
#include <stdio.h>
#define MAX 1000000
// global declaration, all global variables contain 0 initially
int l=0 ;
int primes[MAX] ;
bool sieve[MAX] ;

void genPrimes()
{
primes[l++] = 2 ;
sieve[0]=sieve[1]=1;;

long long i,j ;

for(j=4;j<MAX;j+=2)
sieve[j] = 1 ;

for(i=3;i<MAX;i+=2)
{
if(sieve[i]==0)
{
primes[l++] = i ;
for(j=i*i;j<MAX;j+=i)
sieve[j] = 1 ;
}
}
}
int main()
{
    genPrimes();
    for(int i=0; i<10; i++)
    {

        printf("%d\n",primes[i]);
    }
    return 0;
}
