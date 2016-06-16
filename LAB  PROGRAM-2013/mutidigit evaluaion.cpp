#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXCOLS 80
#define TRUE 1
#define FALSE 0



void stackinit (struct stack *p);

double eval(char[]);

double pop(struct stack *p);

void push(struct stack *p, int x);

int empty(struct stack *);

int isdigit(char);

double oper(char,double,double);



struct stack {

int top;

double items[MAXCOLS];

};

int main()
{

    char symb;

    char exp[MAXCOLS];

    int position = 0;

    struct stack s;

    stackinit (&s);



    while((exp[position++] = getchar()) != '\n');

    exp[--position] = '\0';

    printf("%s%s", "the original postfix exp<b></b>ression is", exp);



    printf("\n%f", eval(exp));


    }

    void stackinit (struct stack *p)

{

      p->top = -1;



      return;

} /* stackinit */

    double eval(char expr[])

    {

    int c, position;

    double  opnd1, opnd2, value;

    struct stack opndstk;

    opndstk.top = -1;

    for (position = 0; (c = expr[position]) != '\0'; position++)



        if(isdigit(c)){



         c = c - '0';

        /* operand-- convert the character representation */

        /*of the digit into double and push it on the stack */



        push(&opndstk, c);}

        else {

        /*operator*/

        opnd2 = pop(&opndstk);

        opnd1 = pop(&opndstk);

        value = oper(c, opnd1, opnd2);

        push(&opndstk, value);

        }

    return 0;}

        int isdigit(char symb)

        {

        return(symb >= '0' && symb <= '9');

        }



        double oper(char symb, double op1, double op2)

        {
                 int j;
        switch(symb)

        {

        case '+' : j =    (op1 + op2);

        break;

        case '-' : j =    (op1 - op2);

      break;

        case '*' : j =    (op1 * op2);

        break;

        case '/' : j =    (op1 / op2);

        break;

        case '$' : j =    (pow(op1, op2));

        break;

        default : printf("%s", "illegal operation");

        exit(1);

        }

        push (&opndstk, j);

         return j;

    }


    double pop (struct stack *p)



{    double y;



      if (empty(p)== TRUE)   {

          printf("\nSTACK UNDERFLOW");

          return -1;

          }

      else

            { y = p->items[p->top];

              p->top--;

            };

          return y;

} /* pop */

void push (struct stack *p, int x)

/* Parameter x is the data to be inserted and it's type is dependent on
129
    the type of the element in the stack  */

{

      if (p->top == MAXCOLS - 1)

      {

          printf("\nSTACK OVERFLOW");
          exit(1);

          }

      else

          p->items [++(p->top)] = x;



      return;

} /* push */

 int empty (struct stack *p)

{

      if (p->top == -1)

          return (TRUE);

      else

          return (FALSE);

}
