#include <stdio.h>
#include <string.h>
int palin(char a[])
{
    int i,len,x=0;
    scanf("%s",a);
    len=strlen(a);
    for(i=0; i<len; i++)
    {
        if(a[i]==a[len-1-i])
        x++;
    }
    if(x==len)
    return 1;
    else
    return 0;

}
int main()
{
    char a[100];
    int y;
    while(1)
    {y=palin(a);
    if(y==1)
    printf("yes\n");
    else
    printf("no\n");
    }


    return 0;
}
