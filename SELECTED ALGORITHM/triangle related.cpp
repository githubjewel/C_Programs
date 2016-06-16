#include<iostream>
07	#include<algorithm>
08	using namespace std;
09
10	int main(){
11	    int n;
12	    cin>>n;
13	    while(n--){
14	        int a[3];
15	        cin>>a[0]>>a[1]>>a[2];
16	        sort(a,a+3);
17	        if(a[2]<(a[0]+a[1]))
18	            cout<<"OK"<<endl;
19	        else
20	            cout<<"Wrong!!"<<endl;
21	        }
22	    return 0;
23	    }
#include<stdio.h>
int main()
{
long int a,b,c,t;
scanf("%ld",&t);
while(t--)
{
scanf("%ld%ld%ld",&a,&b,&c);
if(a+b<=c || b+c<=a || a+c<=b)
printf("Wrong!!\n");
else
printf("OK\n");
}
}
#include <stdio.h>

int main()
{
    int a, b, c, i, k, j, test_case;

    while(scanf("%d", &test_case)==1)
    {
        for(i=0; i<test_case; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(a+b>c && b+c>a && c+a>b)
                printf("OK\n");

            else
                printf("Wrong!!\n");
        }
    }
}
