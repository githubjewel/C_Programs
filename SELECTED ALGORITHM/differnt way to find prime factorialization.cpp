N0-01;
/*
#include <stdio.h>
     #include <iostream.h>

     main()
     {

     	int a, i, g, no_prime, o=0;
     	i = 0;
     	g = 0;
     	no_prime= 0;
     	cout<<"Enter a number:";
     	cin>>a;
     	cout<<endl<<"The number is "<<a<<endl;
     	for (i=2; i<=a; i++)
     	{

     		if (a % i == 0)
     		{
 			cout << i << " is a factor of " << a << endl;
     			++o;
     		}
     	}
     	if (o == 1)
     		cout << "The number " << a <<" is prime\n";
     	else
     		cout << "The number " << a <<" is not prime\n";
     	return 0;
     }
     */
NO-2
/*
Algorithm:
Two = Three = Five = 1 [First ugly number]

long Minimum () {
if ( (2 * Two) minimum than (3 * three) and (5 * Five) ) then
return (2 * Two) and update : Two = Next ugly number

else if ( (3 * Three) minimum than (2 * Two) and (5 * Five) ) then
return (3 * Three) and update : Three = Next ugly number

else if ( (5 * Five) minimum than (3 * three) and (2 * Two) ) then
return (5 * Five) and update : Five = Next ugly number
}

// consecutive two returned value would be same, so carefully choose distinct value.
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int main() {

    int uglynum[1500]={};
    uglynum[0] = 1;
    int p,q,r;

    p=q=r=0;
    int i=1;

    while(uglynum[1499] == 0) {
        int P, Q, R;
        P = uglynum[p]*2;
        Q = uglynum[q]*3;
        R = uglynum[r]*5;

        if (P < Q && P < R) {
            uglynum[i] = P;
            i++;
            p++;
        }
        else if (Q < P && Q < R) {
            uglynum[i] = Q;
            i++;
            q++;
        }
        else if (R < P && R < Q) {
            uglynum[i] = R;
            i++;
            r++;
        }
        else if (P==Q || P==R)
            p++;
        else if (Q == R)
            q++;
    }

    printf("The 1500'th ugly number is %d.\n",uglynum[1499]);

    return 0;
}
*/
NO-03
/*
void printPrimeFactors(int number)
{
	 stack<int> primeStack;
	 assert(number >= 0);
	 for(int i = 2; i <= number; i++) // Test for factors > 1
	 {
		 if(number % i == 0) // It is a factor > 1
		 {
			 bool prime = true;
			 for(int j = 2; j < i; j++) // Test for prime
			 {
				 if(i % j == 0) // It is not prime
					 prime = false;
			 }
			 if(prime)
				 primeStack.push(i);
		 }
	 }
	 while(!primeStack.empty())
	 {
		 cout << primeStack.top() << endl;
		 primeStack.pop();
	 }
}
*/
NO-04
/*
#include <iostream.h>

void PrimeFactors (int );


int main()
{
	int n = 0;
	cout<<"\t\tWelcome to Prime Factors program\n\n";
	cout<<"Enter the number : ";
	cin>>n;
	cout<<"\n\n";
	PrimeFactors(n);

	return 0;
}

void PrimeFactors (int n)
{

	int count = 0;
	int temp = 0;


	for ( int i = 1 ; i <= n ; i++ )
	{

		int j = i - 1;

		while ( j > 1 )
		{
			if ( i % j == 0 )      //Is PRIME
				break;
			else
				j--;
		}

		if ( j == 1 )
		{
			if ( n % i == 0 )
			{
			 cout<<"\n"<<i;    //PRIME factor

				if ( i > temp )
		                          {	temp = i;
				             count++;
                                                     }
			}
		}

	}

	cout<<"\n\nNumber of prime factors of "<<n<<" : "<<count<<"\n\n";
	cout<<"Greatest prime factor is "<<temp<<"\n\n";
}*/
