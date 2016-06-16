int sequence(char s1[],char s2[10000])
{
    long j,i,len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    if(len1>len2) return 0;
    else
    {
        j=0;
        for(i=0; i<len2; i++)
        {
            if(s1[j]==s2[i])
            j++;

        }
        if(j==len1) return 1;
        else return 0;
    }
}
/*#include <stdio.h>
#include <string.h>
char str[300000],str1[300000];
int main()
{
while(scanf("%s %s",str,str1)!=EOF)
{
long long int i,j,k,g;
i=strlen(str);
j=strlen(str1);
g=0;
for(k=0;k<j;k++)
if(str1[k]==str[g])
g++;
if(g==i)
printf("Yes\n");
else
printf("No\n");
}
return 0;
}
