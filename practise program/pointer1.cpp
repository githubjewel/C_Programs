#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p[100];
    for(int i=0; i<100; i++)
    p[i]=(char*)malloc(sizeof(char));
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    scanf("%s",p[i]);
    for(int i=0; i<n; i++)
    printf("%s\n",*p[i]);


    return 0;
}
