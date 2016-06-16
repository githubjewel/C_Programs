#include<stdio.h>
#include <string.h>
int main()
{
char a[20],b[20];
printf("enter a string");
scanf("%s",&a);
strcpy(b,a);//copies string a to b
strrev(b);//reverses string b
if(strcmp(a,b)==0)//compares if the original and reverse strings are same
printf("\n%s is a palindrome",a);
else
printf("\n%s is not a palindrome",a);
return 0;
}
/*#include <stdio.h>
#include <string.h>
char* add(char s1[],char s2[])
{
    long len,c=0,i,j=0,x;
    char *p1,q[10000];
    len=strlen(s1);
    for(i=len-1; i>=0; i--)
    {
        x=s1[i]-'0'+s2[i]-'0'+c;
        q[j]=(x%10)+48;
        c=x/10;
        j++;
    }
    if(c>0)
    q[j]=c+48;
    strrev(q);
    p1=q;
    return p1;
}

int pal(char s1[])
{
   char s2[10000];
   strcpy(s2,s1);
   strrev(s2);
   if(strcmp(s1,s2)==0)
   return 0;
   else return 1;
}
int main()
{
   unsigned long test,i,count;
   char s1[10000],s2[10000],*p;
    scanf("%lu",&test);
    for(i=0; i<test; i++)
    {
        scanf("%s",s1);
        count=0;
        int k=1;
        while(k)
        {
            k=pal(s1);
            count++;
            strcpy(s2,s1);
            strrev(s2);
            p=add(s1,s1);
            strcpy(s1,p);

        }
        printf("%ld %s\n",s1);
    }
}
*/
