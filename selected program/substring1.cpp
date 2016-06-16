#include <stdio.h>
#include <string.h>
int substring(char s1[],char s2[])
{
    int len1,len2,i,j;
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0; i<=len1-len2; i++)
    {
        for(j=0; j<len2; j++)
        {
            if(s1[i+j]!=s2[j]) break;

        }
            if(j==len2) return 1;

    }
    return 0;
}
int main()
{
    char s1[100],s2[100];
    scanf("%s %s",s1,s2);
    int s=substring(s1,s2);
    if(s==1)
    printf("yes\n");
    else
    printf("no\n");
    return 0;
}
