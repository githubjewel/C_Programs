#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define max_size 100

char stack[max_size];

int stack_2[max_size];

char infix[100],postfix[100];

int top=-1,top_2=-1;

void push(char item)
{
    top++;
     stack[top]=item;
}
char pop()
{
     char a;
     a=stack[top];
     top--;
      return a;
}
int precedence(char symbol)
{
  switch(symbol)
   {
      case '+':
      case '-':return 2;
                  break;
      case '*':
      case '/':
      case '%':
      return 4;
               break;
      case '^':return 6;
               break;
     case '(':
     case ')':return 1;
               break;
}
}

int is_operator(char symbol)
{
     switch(symbol)
   {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '(':
        case ')':return 1;
                   break;

        default:
             return 0;
}
}
void conversion()
{
     int i,j=0;

     char symbol;

     stack[++top]='(';

     infix[strlen(infix)]=')';

     for(i=0; i<=strlen(infix); i++)
     {
         symbol=infix[i];

        if(is_operator(symbol)==0)
        {
            postfix[j]=symbol;

            j++;
        }

          else
          {
            if(symbol=='(')

            push(symbol);

            else if(symbol==')')
                {

            while(stack[top]!='(')
             {
                postfix[j]=pop();

                j++;
             }

            pop();//pop out (.

            }

            else
            {

              if(precedence(symbol)>precedence(stack[top]))

                  push(symbol);

              else
                {

                while(precedence(symbol)<=precedence(stack[top]))
                    {

                    postfix[j]=pop();

                    j++;

                    }

                      push(symbol);

                      }

                  }
           }
    }
     /*while(stack[top]!='(')
      {
           postfix[j]=pop();
             j++;
      }*/
      postfix[j]='\0';
}

void push_2(int item)
{
    stack_2[++top_2]=item;
}

int pop_2()
{
    return(stack_2[top_2--]);
}
int main()
{

        char s;

        int k=0,valu1,valu2;

        printf("Enter the valid infix expression:\n\n");

       scanf("%s",infix);

       printf("\nThe corresponding postfix expresion is:\n\n");

       conversion();

       for(int i=0 ; postfix[i]!='\0'; i++)

           printf("%c ",postfix[i]);

           printf("\n");

    /* the code for evaluaion*/


    while( (s=postfix[k++]) != '\0')

    {
        if(isdigit(s))

         push_2(s-'0');

        else
        {
            valu2=pop_2();

            valu1=pop_2();

            switch(s)
            {
               case '+':push_2(valu1+valu2);break;
               case '-':push_2(valu1-valu2);break;
               case '*':push_2(valu1*valu2);break;
               case '/':push_2(valu1/valu2);break;
               case '%':push_2(valu1%valu2);break;
            }
        }
    }
    printf("\nEvaluation result is: %d\n",stack_2[top_2]);



       return 0;
}

