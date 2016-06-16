#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100],d[100];
    long long int i,j,k,len2,len1,len3,sum,x,v,c[1000],s=0,p=0;
    memset(c, 0, sizeof(c));
    scanf("%s %s",a,b);
    len1=strlen(a);
    len2=strlen(b);
    k=0;v=0;
    for(i=0,j=0; i<len1&&j<len2; i++,j++)
    {
        if(a[i]=='0') k++;
        if(b[j]=='0') v++;
    }
    if(k==len1||v==len2)
    {
        printf("0"); return 0;
    }
    if(len1<len2)
    {
        strcpy(d,a);
          strcpy(a,b);
            strcpy(b,d);
            len3=len1;
            len1=len2;
            len2=len3;

    }
    for(i=len2-1; i>=0; i--)
    {
        sum=0;k=0;v=0;
        for(j=len1-1; j>=0; j--)
        {
            sum=sum+(a[j]-'0')*(b[i]-'0')+p;
            x=(sum%10)+c[k+s];c[k+s]=x%10;
            p=x/10; sum=sum/10; k++;
        }
        if(sum>0)
        {
            c[k+s]=sum+p; v++;
        }
        s++;
    }
    for(j=len1+(len2-1)+v-1; j>=0; j--)
    printf("%lld",c[j]);


    return 0;
}
