#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



bool isoperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/') return true;
    return false;
}


int main()
{
    int i;
    int fix[101];
    char a[101],pfix[101],ans[101];

    while(scanf("%s",a)==1)
    {
        int len = strlen(a);
        a[len]=')';
        len++;
        pfix[0]='(';
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
                                if(pfix[top]=='+' || pfix[top]=='-' || pfix[top]=='*' || pfix[top]=='/')
                                {

                                    ans[crr]=pfix[top];
                                    pfix[top]=a[i];
                                    crr++;
                                }

                                else
                                {
                                    top++;
                                    pfix[top]=a[i];
                                }
                        }

                        else if(a[i]=='*' || a[i]=='/')
                        {
                                if(pfix[top]=='*' || pfix[top]=='/')
                                {

                                        ans[crr]=pfix[top];
                                        pfix[top]=a[i];
                                        crr++;
                                }
                                else
                                {
                                        top++;
                                        pfix[top]=a[i];
                                }
                        }
                }

                else if(a[i]==')')
                {
                        while(pfix[top]!='(')
                        {

                            ans[crr]=pfix[top];
                            crr++;
                            top--;
                        }
                        top--;
                }

                else if(a[i]=='(')
                {
                        top++;
                        pfix[top]=a[i];
                }
            }
        }

        printf("Postfix : ");
        for(i=0;i<crr;i++) printf("%c",ans[i]);
        printf("\n");
        int x,y,res=0;

        top=-1;
        for(i=0;i<crr;i++)
        {
            if(isdigit(ans[i]))
            {
                top++;
                fix[top]=ans[i]-'0';
            }

            else if(isoperator(ans[i]))
            {
                x=fix[top];
                top--;
                y=fix[top];

                if(ans[i]=='+')
                {
                    fix[top]=y+x;
                }

                else if(ans[i]=='-')
                {
                    fix[top]=y-x;
                }

                else if(ans[i]=='*')
                {
                    fix[top]=y*x;
                }
                else if(ans[top]=='/')
                {
                    fix[top]=y/x;
                }
            }
        }

        printf("Postfix evalution: ");
        printf("%d\n",fix[0]);

    }

    return 0;
}
