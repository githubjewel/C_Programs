#include <stdio.h>
#include <string.h>
int main()
{
   for(;;) {char a[100],b[100];

    gets(a);
    gets(b);
    printf("%s\n",strlwr(a));
    printf("%s\n",strupr(a));
    printf("%s\n",strcat(a,b));
    printf("%d\n",strcmp(a,b));



}    return 0;
}

