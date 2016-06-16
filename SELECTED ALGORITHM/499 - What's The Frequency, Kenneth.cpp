#include <stdio.h>
#include <string.h>
char s2[1000];
int max(char a1[])
{
    len=strlen(a1);
    maxi=-10000;
    for(i=0; i<len; i++)
    {
        if(a1[i]-48 > maxi)
        maxi=a1[i]-48;
    }
    return maxi;
}

int main()
{
    char s[1000];
    memset(s2, '0'; sizeof(s2));

   while(gets(s))
   {
       len=strlen(s);
       i=0;k=0;
      while(s[i++]!='\0')
      {
          if(s[i]>='A' && s[i]<='Z')

          {
            k=s[i]-65;
            sum=s2[k]+1;
            s2[k]=sum+48;
          }
          if(s[i]>='a' && s[i]<='z'){

            k=s[i]-97;
            sum=s2[k]+1;
            s2[k]=sum+48;
            }

      }
      max=(s2);
      for(i=0; i<len; i++)
      {
          if(s1[i])
      }
   }

    return 0;
}
