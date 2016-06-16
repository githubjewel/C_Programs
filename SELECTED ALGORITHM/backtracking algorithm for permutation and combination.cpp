#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
char arr[]={'a','b','c','d'};
vector<char>result;
int taken[20]={0};
void call()
{
    if(result.size()==4)
    {
        for(int i=0;i<4;i++)
        printf("%c",result[i]);
        puts("");
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1; result.push_back(arr[i]);
            call();
            taken[i]=0; result.pop_back();
        }
    }
}
int main()
{
    call();
}
/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char p[15];
        cin>>p;
        int len=strlen(p);
        sort(p,p+len);
        do
        {
            cout<<p<<endl;
        }while(next_permutation(p,p+len));
        cout<<endl;
    }
    return 0;
}*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int myints[] = {1, 2, 3};

  cout << "The 3! possible permutations with 3 elements:\n";

  sort (myints,myints+3);

  do {
    cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
  } while ( next_permutation (myints,myints+3) );

  return 0;
}

*/
