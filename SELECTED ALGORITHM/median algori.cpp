
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    long  long n,i=0,sum,a[100000];
    while(scanf("%lld",&n)!=EOF)
    {
        a[i]=n;
        sort(a,a+i+1);
        if((i+1)%2!=0)
        {
            printf("%lld\n",a[(i/2)]);
        }
        else
        {
            sum=(a[(i+1)/2]+a[(i+1)/2-1])/2;
            printf("%lld\n",sum);
        }
        i++;
    }
    return 0;
}

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
    long long N;
    vector<long long> V;

    while(cin >> N) {

        V.push_back(N);
        sort(V.begin(), V.end());

        int size = V.size();

        if (size % 2 == 0)
            cout << (V[size/2] + V[size/2 - 1]) / 2 << endl;
        else
            cout << V[(size/2)] << endl;
    }

    return 0;
}
