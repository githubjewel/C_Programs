#include <stdio.h>
#include <string.h>
#define For(i,x) for(int i=0; i<x; i++)

int main()
{
      char a[100],s;

	  int len;

	  scanf("%s",a);

      For(i,strlen(a))
	  {
		  s=a[i];
	  }

	  printf("\n\nthe last digit of the big number is:= %c\n",s);

	return 0;
}