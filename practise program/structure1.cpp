#include <stdio.h>
#include <math.h>
struct student
{
  char name[100];
  int s1,s2,s3,total;
  double avg,gpa;
};
int main()
{
    FILE *f1;
    student s[100];
    int i,n=0,j;
    f1=fopen("in.txt","r");
    fscanf(f1,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(f1,"%s %d %d %d",s[i].name,&s[i].s1,&s[i].s2,&s[i].s3);
        s[i].total=(s[i].s1+s[i].s2+s[i].s3);
        s[i].avg=(s[i].total)*1.00/3;
        if(s[i].avg>=80)
        s[i].gpa=4.00;
         else if(s[i].avg>=70)
        s[i].gpa=3.00;
         else
        s[i].gpa=2.00;
    }
    for(i=0; i<n; i++)
    {
        printf("the information of %d studet is:\n\n",i+1);
        printf("%s\n",s[i].name);
        printf("%d\n",s[i].total);
        printf("%.2lf\n",s[i].avg);

    }
    return 0;
}
