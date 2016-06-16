#include <stdio.h>
#include <string.h>
int counter;
int tower(int n, char a, char b, char c)
{
    if(n==1)
    {
        printf("%c to %c\n",a,c);

        counter++;
    }
    else
    {
        tower(n-1,a,c,b);

        printf("%c to %c\n",a,c);

        counter++;

        tower(n-1,b,a,c);////tower(n-1,b,c,a);
    }
}

int main()
{

            int n;

            scanf("%d",&n);

            counter=0;
            /* total move ber korar jonno formula */

           //total_move = (pow(2,n)-1);

            if(n>0) tower(n,'a','b','c');

            else printf("Invalid number\n");

            printf("Total number of moves: %d\n",counter);




    return 0;
}
