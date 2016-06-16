#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int isoper;
    char opert;
    int value;
};
int top=0;
void push(node ch, node stack[])
{
    stack[top]=ch;
    top++;
}
node pop(node stack[])
{
    top--;
    return stack[top];
}
int is_operator(char c , char op[])
{
	int i = 0;
    if(c>47 && c<58) return 0;
	while(op[i])
	{
		if(c == op[i])return 1;
		i++;
	}
	return 2;
}
int main()
{
    char infix[99];
    node postfix[99];
    printf("Infix: ");
    gets(infix);
    char oper[10]="+-*/%^";
    node stack[99];
    int i , j;
    int precedence[270];
    precedence['+']=precedence['-']=1;
    precedence['*']=precedence['/']=2;
    precedence['%']=3;
    precedence['^']=4;

    node x;
    x.isoper=2;
    x.opert='(';
    push(x,stack);
    j=strlen(infix);
    infix[j]=')';
    infix[j+1]=0;

    for(i=0,j=0;infix[i];i++)
    {
        if(is_operator(infix[i], oper)==1)
        {
            if(stack[top-1].isoper==1 && precedence[stack[top-1].opert]>=precedence[infix[i]])
            {
                while(true)
                {
                    node ch;
                    ch=pop(stack);
                    if(ch.isoper==1 && precedence[ch.opert]>=precedence[infix[i]])
                    {
                        postfix[j++]=ch;
                    }
                    else
                    {
                        push(ch,stack);
                        break;
                    }
               }
            }
            node y;
            y.isoper=1;
            y.opert=infix[i];
            push(y,stack);
        }
        else if(infix[i]==')')
        {
               while(true)
               {
                    node ch;
                    ch=pop(stack);
                    if(ch.isoper==2 && ch.opert=='(') break;
                    else
                    {
                        postfix[j] = ch;
                        j++;
                    }
               }
        }
        else if(infix[i]=='(')
        {
            node ch;
            ch.isoper=2;
            ch.opert='(';
            push(ch,stack);
        }
         else if(infix[i]!=' ')
         {
            if(is_operator(infix[i],oper)==0)
            {
                int k=0;
                while(infix[i]>47 && infix[i]<58)
                {
                    k=k*10+infix[i++]-'0';
                }
                i--;
                node ch;
                ch.isoper=0;
                ch.value=k;
                postfix[j++]=ch;
            }
            else
            {
                node ch;
                ch.isoper=2;
                ch.opert=infix[i];
                postfix[j++]=ch;
            }
         }
    }
    printf("Postfix: ");
    int f=0;
    for(i=0;i<j;i++)
    {
        if(f==1 && i<j) printf(",");
        f=1;
        if(postfix[i].isoper==0) printf("%d",postfix[i].value);
        else printf("%c",postfix[i].opert);
    }
    printf("\n");
    return 0;
}
