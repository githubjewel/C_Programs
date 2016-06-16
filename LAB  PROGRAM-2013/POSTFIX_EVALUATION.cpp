
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define stack_size 100

int stack[stack_size];

char postfix[100];

int top=-1;       /* Global declarations */

void push(int item)
{                       /* Function for PUSH operation */
    stack[++top]=item;
}

int pop()
{                      /* Function for POP operation */
    return(stack[top--]);
}

int main()
{                         /* Main Program */
    char symbol;

    int i=0,valu1,valu2;

    printf("Enter the Postfix Expression :\n\n");

    scanf("%s",postfix);

    while( (symbol=postfix[i++]) != '\0')
    {
        if(isdigit(symbol))

         push(symbol-'0');
         /* Push the operand */
        else
        {        /* Operator,pop two  operands */
            valu2=pop();

            valu1=pop();

            switch(symbol)
            {
               case '+':push(valu1+valu2);break;
               case '-':push(valu1-valu2);break;
               case '*':push(valu1*valu2);break;
               case '/':push(valu1/valu2);break;
               case '%':push(valu1%valu2);break;
            }
        }
    }
    printf("\nEvaluation result is: %d\n",stack[top]);
}
