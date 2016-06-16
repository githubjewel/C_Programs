#include<stdio.h>
#include<string.h>
#include <math.h>
int s[100] , top = -1;
void push(int x)
{
	top = top+1;
	s[top] = x;
}
int pop()
{
	int n = s[top];
	top = top-1;
	return n;
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
	char p[100] , q[100] ;
	printf("Postfix : ");
	gets(q);
	int n = 0;
	int len = strlen(q);
	int i , res , a ,b;
	char op[10] = "+-*/%^";
	q[len] = ')';
	q[len+1] = NULL;
	for(i = 0 ; q[i] != ')' ; i++)
	{
		if(is_operator(q[i] , op))
		{
			a = pop();
			b = pop();
			if(q[i] == '+')
				res = b + a;
			else if(q[i] == '-')
				res = b-a;
			else if(q[i] == '*')
				res = a*b;
			else if(q[i]=='/') res = b/a;
			else if(q[i]=='%') res=b%a;
			else if(q[i]=='^') pow(b,a);
			push(res);
		}
		else
		{
			if(q[i] != ',' && q[i]!=' ')
			{
				n = 10*n+(q[i] - '0');
				continue;
			}
			else
			{

				if(n != 0)
                push(n);
				n = 0;
			}
		}
	}
	printf("Ans : %d\n",s[top]);
	return 0;
}
