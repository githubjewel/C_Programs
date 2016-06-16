#include<stdio.h>
#include<string.h>
#define Size 1000
struct data
{
    int val;
    int sta;
};
char s[Size];
int top = -1;
void push(char x)
{
	top = top+1;
	s[top] = x;
}
int pop()
{
	int x = s[top];
	top = top - 1;
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
	int j = 0;
	int l , k;
	int c = 0;
	char q[100] , p[100] ;
	data st[100];
	char pre[100];
	char op[10] = "+-*/^";
	int pres[300];
	pres['+'] = pres['-'] = 1;
	pres['*'] = pres['/'] = 2;
	pres['^'] = 3;
	printf("Infix : ");
	gets(pre);
	k=0;
	int len2 = strlen(pre);
	for(l = 0 ; l < len2 ; l++)
	{
		if(!is_operator(pre[l] , op))
		{
			c = 10*c+(pre[l] - '0');

		}
		else
		{


		}
	}
	q[k++] = c+'0';
	q[k] = NULL;
	//for(l = 0 ; l < k ; l++)
		//printf("%c ",q[l]);
	int len = strlen(q);
	q[len] = ')';
	q[len+1] = NULL;
	push('(');
	for(int i = 0 ; i < len+1 ; i++)
	{
		if(q[i] == '(')
			push(q[i]);
		else if(q[i] >= 48 && q[i] <= 122)
			p[j++] = q[i];
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
