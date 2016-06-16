#include<iostream>

void main()
{
	using namespace std;

	int num1,num2,a,b;
	cout<<"Enter 1st no. ";
	cin>>num1;
	cout<<"Enter 2nd no. ";
	cin>>num2;
	a=num1;
	b=num2;
	while(a!=b)
	{
		if(a<b)
		{
			a+=num1;
		}
		else
		{
			b+=num2;
		}
	}

	cout<<"LCM is = "<<a;
	cin.get();
}
