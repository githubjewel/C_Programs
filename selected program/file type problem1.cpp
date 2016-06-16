#include <stdio.h>
int main()
{
    char s[100],d[100],c;
    FILE *p1,*p2;
    scanf("%s",s);

    scanf("%s",d);
    p1=fopen(s,"r");
    p2=fopen(d,"w");
    while(fscanf(p1,"%c")==1)
    {
        fprintf(p2,"%c");
    }
    fclose(p1);
    fclose(p2);
    return 0;
}
