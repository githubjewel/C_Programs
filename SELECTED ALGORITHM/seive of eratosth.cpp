 #include <stdio.h>
#include <string.h>
char sieve[500000];
char isPrime(int n){
    if (n == 2)
        return 1;
    else if (! (n % 2))
        return 0;
    else {
        return sieve[(n-1)/2];
    }
}

void init(){
    int i, cur,k;

    memset(sieve,1,sizeof(sieve));


    /* sieve of eratosthenes */

    sieve[0] = 0;
    for (i = 3; i <= 1001; i+=2){
        if (sieve[(i-1)/2]){
            cur = 3*i;
            while (cur < 1000000){
                sieve[(cur-1)/2] = 0;
                cur = cur + i + i;
            }
        }
    }
  for(int k=0; k<10000000000; k++)
  {
      if(isPrime(k)) printf("%d\n",k);
  }
}
    int main()
    {
        init();
        return 0;
    }
