
#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000];
    int len,c,i,d;
    scanf("%s",s);
    len=strlen(s);
    c=0,d=0;
    for(i=0; i<len; i++)
    {
      c=s[i]-'0'+d*10;
      d=c%10;
    }
    printf("%d",d);
}
