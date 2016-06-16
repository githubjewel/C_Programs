#include <stdio.h>
int main()
{
    int t=1,i,j,k,n;
    while(scanf("%d",&n)==1)
    {
        int a[1000];
        for(i=0; i<n; i++)
        scanf("%d",&a[i]);
        long max=0;
        for(i=0; i<n; i++)
        {
            for(j=i; j<n; j++)
            {
                long pro=1;
                for(k=i; k<=j; k++)
                {
                    pro*=a[k];
                }
                if(max<pro)
                max=pro;
            }
        }
        printf("Case #%d: The maximum product is %ld.\n\n",t,max);t++;
    }
    return 0;
}
/*#include <stdio.h>
int main()
{
    int cases=0,counter=1;
    while(scanf("%d",&cases)==1){
        int i,j,k,x[cases];
        for(i=0;i<cases;i++)
          scanf("%d",&x[i]);
        long max=0;
        for (i = 0; i < cases; i++) {
                for (j = i; j < cases; j++) {
                    long pro = 1;
                    for (k = i; k <= j; k++) {
                        pro*=x[k];
                    }
                    if(max<pro)
                        max = pro;
                }
            }
        printf("Case #%d: The maximum product is %ld.\n\n",counter,max);
        counter++;
    }
    return 0;
}

*/
