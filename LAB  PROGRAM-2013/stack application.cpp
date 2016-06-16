#include <stdio.h>
#include <string.h>
int top=0;
void push(char ch, char stack[])
{
    stack[top]=ch;
    top++;
}
char pop(char stack[])
{
    top--;
    return stack[top];
}
bool isoperator(char ch, char oper[])
{
    int i=0;
    while(oper[i])
    {
        if(ch==oper[i]) return true;
        i++;
    }
    return false;
}
int main()
{
    char infix[99], postfix[99];
    printf("Infix: ");
    printf("%d %d", '0', '9');
    gets(infix);
    int precedence[270];
    precedence['+']=precedence['-']=1;
    precedence['*']=precedence['/']=2;
    precedence['%']=3;
    precedence['^']=4;
    char oper[10]="+-*/%^";
    char stack[99];
    int i , j;
    push('(',stack);
    j=strlen(infix);
    infix[j]=')';
    infix[j+1]=0;
    for(i=0,j=0;infix[i];i++)
    {
        if(isoperator(infix[i], oper))
        {
            if(isoperator(stack[top-1],oper) && precedence[stack[top-1]]>=precedence[infix[i]])
            {
                while(true)
               {
                    char ch;
                    ch=pop(stack);
                    if(isoperator(ch,oper) && precedence[ch]>=precedence[infix[i]])
                    {
                        postfix[j]=ch;
                        j++;
                    }
                    else
                    {
                        push(ch,stack);
                        break;
                    }
               }
            }
            push(infix[i],stack);
        }
        else if(infix[i]==')')
        {
                while(true)
               {
                    char ch;
                    ch=pop(stack);
                    if(ch=='(') break;
                    else
                    {
                        postfix[j]=ch;
                        j++;
                    }
               }
        }
        else if(infix[i]=='(') push(infix[i],stack);
        else if(infix[i]!=' ')postfix[j++]=infix[i];
    }
    printf("Postfix: ");
    for(i=0;i<j;i++)
    printf("%c",postfix[i]);
    printf("\n");
    return 0;
}
