
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
        {
            int k=0;

            while(isdigit(symbol))
            {


                k=symbol-'0'+k*10;

                symbol=postfix[i];

                i++;



           }
            i--;



           push(k);
         }
         /* Push the operand */

        else if(postfix[i]!=',')

        {        /* Operator,pop two  operands */
            valu2=pop();

            printf("%d ",valu2);

            valu1=pop();

            printf("%d ",valu1);

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
