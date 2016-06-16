#include<stdio.h>
#include <string.h>
#include <math.h>
#define size 100

void sort_fun(long array[],long item_lowest,long item_middle,long item_high)
{

    long b,c,p,a,v[size];

          a=item_lowest;

          b=item_lowest;

        c=item_middle+1;

    while((a<=item_middle)&&(c<=item_high))
    {

         if(array[a]<=array[c])
         {
             v[b]=array[a];

             a++;
         }
         else
         {
             v[b]=array[c];

             c++;
         }

         b++;
    }

    if(a>item_middle)
    {
         for(p=c;p<=item_high;p++)
         {
             v[b]=array[p];

             b++;
         }
    }
    else
    {
         for(p=a;p<=item_middle;p++)
         {
             v[b]=array[p];

             b++;
         }
    }

    for(p=item_lowest;p<=item_high;p++)
    {
         array[p]=v[p];
    }
}
void find(long array[],long item_lowest,long item_highest)
{

    long item_middle;

    if(item_lowest<item_highest)
    {
         item_middle=(item_lowest+item_highest)/2;

         find(array,item_lowest,item_middle);

         find(array,item_middle+1,item_highest);

         sort_fun(array,item_lowest,item_middle,item_highest);
    }
}



int main()
{

    long array[size],length;

    printf("Enter a number: \n");

    scanf("%ld",&length);

    for(int v=0; v<length; v++)
    {
         scanf("%ld",&array[v]);
    }

    find(array,0,length-1);

    printf("After sorting elements are: \n\n");

    for(int v=0; v<length ; v++)
    {
         printf("%ld ",array[v]);
    }
             printf("\n");
   return 0;
}


