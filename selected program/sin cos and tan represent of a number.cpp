#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    while(scanf("%d",&n))
    {

        printf("%.2lf\n",sin(n*M_PI/180));

        printf("%.2lf\n",cos(n*M_PI/180));

        printf("%.2lf\n",tan(n*M_PI/180));

        printf("%.2lf\n",1/tan(n*M_PI/180));

        printf("%.2lf\n",1/cos(n*M_PI/180));

        printf("%.2lf\n",1/sin(n*M_PI/180));

        printf("sin inverse is: %.2lf\n",asin(n)*180/M_PI);// sin inverse

        printf("cos inverse is: %.2lf\n",acos(n)*180/M_PI);

        printf("the cot inverse is: %.2lf\n",atan(1.0/n)*180/M_PI);

        printf("the sec inverse is: %.2lf\n",acos(1.0/n)*180/M_PI);

        printf("the cosec inverse is: %.2lf\n",asin(1.0/n)*180/M_PI);

    }
    return 0;
}
