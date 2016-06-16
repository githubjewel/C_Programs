#include <stdio.h>
#include <math.h>
int main()
{
    int n,t=0,d;
    while(scanf("%d",&n)==1 && (n>=0))
    {
        d=ceil(log(n)/log(2));
        printf("Case %d: %d\n",++t,d);
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

	int main ()
	{
	    int n;
	    int cases = 0;

	    while ( scanf ("%d", &n) && n >= 0 ) {
	        printf ("Case %d: %0.lf\n", ++cases, ceil (log (n) / log (2)));
	    }

	    return 0;
	}
