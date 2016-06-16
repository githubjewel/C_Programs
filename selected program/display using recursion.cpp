#include <stdio.h>
#include <string.h>
void alpha(char ch)
{
    printf("%c\t",ch);
    if(ch<'Z') alpha(ch+1);
}
int main()
{
    alpha('A');
    return 0;
}
