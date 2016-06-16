#include <stdio.h>
#include <math.h>
#include <string.h>
#define max_size 100
char stack[max_size];

char infix[100],postfix[100];

int top=-1;

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
int main()
{

       printf("Enter the valid infix expression:\n\n");

       scanf("%s",infix);

      printf("\nThe corresponding postfix expresion is:\n\n");

      conversion();

      for(int i=0 ; postfix[i]!='\0'; i++)

           printf("%c ",postfix[i]);



       return 0;
}
