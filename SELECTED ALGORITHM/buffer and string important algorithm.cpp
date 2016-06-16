#include<cstdio>  /* uva maximum gcd related*/
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N; cin >> N; cin.ignore();
    while(N--) {
        string line;
        stringstream ss;
        int temp, maxgcd=0;
        vector<int> v;

        getline(cin, line);
        ss << line;

        while(ss >> temp) v.push_back(temp);

        for(int i=0; i<v.size()-1; i++) {
            for(int j=i+1; j<v.size(); j++) {
                int currgcd = gcd(v[i], v[j]);
                if (currgcd > maxgcd) maxgcd = currgcd;
            }
        }

        printf("%d\n", maxgcd);
    }

    return 0;
}
Input line to string variable str
and split the line and store to num[] arry
/*#include <stdio.h>
02	#define max(a,b) (a>b)?a:b
03	int num[105];
04	int gcd(int a,int b)
05	{
06	    if(b)
07	        return gcd(b,a%b);
08	    return a;
09	}
10	int main()
11	{
12	    int c=0,i=0,j=0,k,m;
13	    char buffer[100];
14	    gets(buffer);
15	    while(buffer[i])
16	        c=c*10+buffer[i++]-'0';
17	    while(c--)
18	    {
19	        gets(buffer);
20	        i = 0;
21	        j = 0;
22	        while(buffer[i])
23	        {
24	            num[j]=0;
25	            while(buffer[i]&&buffer[i]!=' ')
26	                num[j]=num[j]*10 + buffer[i++]-'0';
27	            while(buffer[i]==' ')
28	                i++;
29	            j++;
30	        }
31	        m = 1;
32	        for(i=0;i<j;i++)
33	            for(k=i+1;k<j;k++)
34	                m = max(m,gcd(num[i],num[k]));
35	        printf("%d\n",m);
36	    }
37	    return 0;
38	}
