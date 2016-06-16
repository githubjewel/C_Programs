#include<stdio.h>
#include<string.h>
#define Size 1000
char s[Size];
int top = -1;
void push(char x)
{
	s[++top] = x;
}
int pop()
{
	int x = s[top--];
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
	int j = 0,len,i,pres[300];
	char q[100] , p[100],op[10] = "+-*/^";
	pres['+'] = pres['-'] = 1;
	pres['*'] = pres['/'] = 2;
	pres['^'] = 3;
	printf("Given Infix : ");
	gets(q);
	len = strlen(q);
	q[len] = ')';
	q[len+1] = NULL;
	push('(');
	for(i = 0 ; i < len+1 ; i++)	{
		if(q[i] == '(') push(q[i]);
		else if(q[i] >= 48 && q[i] <= 122)  p[j++] = q[i];
		else if(is_operator(q[i] , op))
		{
			if(is_operator(s[top],op) && pres[s[top]] >= pres[q[i]])
				{
					while(true)
					{
						char ch;
						ch = pop();
						if(is_operator(ch , op) && pres[ch] >= pres[q[i]])
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
	p[j++] = NULL;
	printf("postfix expression : %s\n",p);
	return 0;

}
