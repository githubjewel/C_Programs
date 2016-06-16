#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

bool isoperator(char ch)
{
     if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%') return true;
     return false;
}


int main()
{
    int i;
    int evaluate[100];
    char a[100],stack[100],ans[100];
    printf("Enter a single digit expression:\n");
    while(scanf("%s",a)==1)
    {
        int len = strlen(a);
        a[len]=')';
        len++;
        stack[0]='(';
        int top=0;
        int crr=0;

        for(i=0;i<len;i++)
        {
            if(isdigit(a[i]))
            {

                ans[crr]=a[i];
                crr++;
            }

            else
            {

                if(isoperator(a[i]))
                {
                        if(a[i]=='+' || a[i]=='-')
                        {
                                if(stack[top]=='+' || stack[top]=='-' || stack[top]=='*' || stack[top]=='/' || stack[top] == '%')
                                {

                                    ans[crr]=stack[top];
                                    stack[top]=a[i];
                                    crr++;
                                }

                                else
                                {
                                    top++;
                                    stack[top]=a[i];
                                }
                        }

                        else if(a[i]=='*' || a[i]=='/' || a[i]=='%')
                        {
                                if(stack[top]=='*' || stack[top]=='/' || stack[top]=='%')
                                {

                                        ans[crr]=stack[top];
                                        stack[top]=a[i];
                                        crr++;
                                }
                                else
                                {
                                        top++;
                                        stack[top]=a[i];
                                }
                        }
                }

                else if(a[i]==')')
                {
                        while(stack[top]!='(')
                        {

                            ans[crr]=stack[top];
                            crr++;
                            top--;
                        }
                        top--;
                }

                else if(a[i]=='(')
                {
                        top++;
                        stack[top]=a[i];
                }
            }
        }

        printf("\nPostfix form --> ");
        for(i=0;i<crr;i++) printf("%c",ans[i]);
        printf("\n");


        int x,y,res=0;
        top=-1;
        for(i=0;i<crr;i++)
        {
            if(isdigit(ans[i]))
            {
                top++;
                evaluate[top]=ans[i]-'0';

            }

            else if(isoperator(ans[i]))
            {
                x=evaluate[top];
                top--;
                y=evaluate[top];

                if(ans[i]=='+')
                {
                    evaluate[top]=y+x;
                }

                else if(ans[i]=='-')
                {
                    evaluate[top]=y-x;
                }

                else if(ans[i]=='*')
                {
                    evaluate[top]=y*x;
                }
                else if(ans[i]=='/')
                {
                    evaluate[top]=y/x;
                }
                else if(ans[i]=='%')
                {
                    evaluate[top]=y%x;
                }
            }
        }

        printf("Postfix evaluation --> ");
        printf("%d\n",evaluate[0]);
        printf("\nEnter a single digit expression:\n");
    }

    return 0;
}
