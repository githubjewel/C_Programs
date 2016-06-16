#include<stdio.h>
#include<string.h>
#define Size 100
int top = -1;
char s[Size];
void push(char n)
    {
        if(top == Size-1)
    {
    printf("Full");
    return;
    }
        top = top+1;
        s[top] = n;
    }
    int pop()
    {
        int x = s[top];
        top = top-1;
        return x;
    }
    bool is_operator(char c , char op[])
    {
        int i = 0;
        while(op[i])
        {
            if(c == op[i])return true;
            i++;
        }
        return false;
    }
        int main()
        {
            int j=0;
            char p[100] , q[100];
            char op[10] = "+-*/~";
            int prece[300];
            prece['+'] = prece['-'] = 1;
            prece['*'] = prece['/'] = 2;
            push('(');
            gets(q);
            int len = strlen(q);
            q[len] = ')';
            q[len+1] = NULL;
            for(int i = 0 ; i <= len+1 ; i++)
            {
                if(q[i] == '(')
                push(q[i]);
                else if((q[i] >= 65 && q[i] <= 122))
                {
                    p[j++] = q[i];
                }
                else if(is_operator(q[i] , op))
                {
                    if(is_operator(s[top],op) && prece[s[top]] >= prece[q[i]])
                    {
                        while(true)
                        {
                            char ch;
                            ch = pop();
                            if(is_operator(ch , op) && prece[ch] >= prece[q[i]])
                            {
                                p[j++] = ch;
                            }
                            else
                            {
                                push(ch);
                                break;
                            }
                        }
                    }
                    push(q[i]);
                }
                else if(q[i] == ')')
                {
                    while(true)
                    {
                        char c = pop();
                        if(c == '(')break;
                        else
                        p[j++] = c;
                    }
                }
            }
            p[j] = NULL;
            printf("%s\n",p);
            return 0;
        }
