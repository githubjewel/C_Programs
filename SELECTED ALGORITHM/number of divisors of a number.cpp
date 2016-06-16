#include <stdio.h>
#include <math.h>
#define LLU long long unsigned
#include <stdio.h>
#define MAX 1000000

int l=0 ;
int primes[MAX] ;
bool sieve[MAX] ;
LLU NumOfDiv(LLU n)
{
int tmp = sqrt((double)n),i ;
LLU ret = 1 ;

for(i=0;primes[i]<=tmp;i++)
{
if(n % primes[i] == 0)
{
LLU cnt = 0 ;
while(n % primes[i] == 0)
{
cnt ++ ;
n /= (LLU)primes[i] ;
}
ret *= (cnt+1) ;
tmp = sqrt((double)n) ;
}
}

if(n>1) ret *= 2 ;

return ret ;
}

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
    LLU n,x;

    scanf("%llu",&n);
    x=NumOfDiv(n);
    printf("%llu ",x);

}
