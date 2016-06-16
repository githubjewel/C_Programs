#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long int len;
char s[100000];
void multiply(long int i)
{
    long int carry=0,j,valu2,valu1;
     for(j=0; j<len; j++)
     {
         valu1=(int)s[j]-48;
         valu2=(i*valu1)+carry;
         s[j]=(char)(valu2%10)+48;
         carry=valu2/10;
     }
     while(carry)
     {
         s[j++]=(char)(carry%10)+48;
         carry=carry/10;
     }
len=j;
     s[j]='\0';


}
int main()
{
    long int n,i;
    while(scanf("%ld",&n)!=EOF)
    {

        if(n==0 || n==1)
        {
            printf("%ld!\n1\n",n); continue;

        }
        s[0]='1';
        s[1]='\0';
        len=1;
        for(i=2; i<=n; i++)
        multiply(i);
        reverse(s,s+len);
        printf("%ld!\n",n);
        printf("%s\n",s);
    }
}
