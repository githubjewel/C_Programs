#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

long array[100];

long change(long first_item, long last_item)
{
    long fixed,temp1,temp2;

     fixed = array[last_item];

     temp1= first_item - 1;

    for(int j = first_item; j < last_item; j ++)
    {
        if(array[j] <= fixed)
        {
            temp1 ++;

            temp2 = array[temp1];

            array[temp1] = array[j];

            array[j] = temp2;
        }
    }
    temp1 ++;

    temp2 = array[temp1];

    array[temp1] = array[last_item];

    array[last_item] = temp2;

    return temp1;
}


void sort_fun(long first_item, long last_item)
{
    long f;

    if(first_item < last_item)
    {

         f= change(first_item , last_item);

        sort_fun(first_item, f - 1);

        sort_fun(f + 1, last_item);
    }
}




int main()
{
	 long lenght,x;


	printf("Enter a number \n");

	   scanf("%ld",&lenght);

	for(int v = 0; v < lenght; v++)

		 scanf("%ld",&array[v]);

	sort_fun(  0, lenght-1);

	printf("\nThe sorted array is:  \n");

	 for(int v=0; v<lenght ; v++)

		printf(" %ld ", array[v]);

		printf("\n");

		 return 0;

}





