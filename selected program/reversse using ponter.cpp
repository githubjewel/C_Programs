#include <stdio.h>
#include <string.h>
int main()
{
    char *p,a[100];
    int i,j,s,len;
    gets(a);
    p=a;
    len=strlen(a);
    for(i=len-1; i>=0; i--)
    printf("%c",*(p+i));
    return 0;
}
