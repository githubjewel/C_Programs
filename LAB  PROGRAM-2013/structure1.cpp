#include <stdio.h>
#include <math.h>
struct student
{
    char name[100];
    int roll,mark;
};
int main()
{
    student s1[100];
    int n,i,j,a[100];
    FILE *f1;
    f1=fopen("in.txt","r");


        fscanf(f1,"%d",&n);
        for(i=0; i<n; i++)
        {
            fscanf(f1,"%s %d %d",s1[i].name,&s1[i].roll,&s1[i].mark);

        }
      for(i=0; i<n; i++)
      {
          printf("the information of %d student is:\n",i+1);
          printf("%s\n",s1[i].name);
                  printf("%d\n",s1[i].roll);
                          printf("%d\n",s1[i].mark);
      }

}
