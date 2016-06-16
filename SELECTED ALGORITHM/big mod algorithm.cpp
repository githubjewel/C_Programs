#include<iostream>
using namespace std;
int rec(long long int b, long long int p, long long int m) {

if (p==0) { return (1%m); }
else if (p==1) { return (b%m); }
else if (p%2==0) { return (rec((b%m*b%m)%m, p/2, m)); }
else { return (b*rec(b, p-1, m))%m; }
}
int main()
{
long long int b , p , m;
while(cin>>b>>p>>m)
{
int md = rec(b,p,m);
cout<<md<<endl;
}
return 0;
}
/* TIMIT LIMIT
#include <stdio.h>
#include <math.h>
long sqare(long s)
{
    return s*s;
}
long mod_gen(long b, long p, long m)
{
    if(p==0) return 1;
    else if(p==1) return (b%m);
    else if(p%2==0)
        return sqare(mod_gen(b, p/2, m))%m;
        else
          return ((b%m)*mod_gen(b, p-1, m))%m;
}
int main()
{
    long b,p,m,res;
    while(scanf("%ld %ld %ld",&b,&p,&m))
    {
        res=mod_gen(b, p, m);
        printf("%ld\n",res);
    }
    return 0;
}











#include<stdio.h>
long square(long s){
return s*s;
}
long bigmod(long b, long p, long m){
if (p == 0)
return 1;
else if (p%2 == 0)
return square( bigmod (b,p/2,m)) % m; // square(x) = x * x
else
return ((b % m) * bigmod( b,p-1,m)) % m;
}
int main(){
long b,p,m,sum;
while(scanf("%ld%ld%ld",& b,& p,& m)){
sum = bigmod( b, p, m);
printf("%ld\n", sum);
}
return 0;}

