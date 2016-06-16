#include <stdio.h>
#include <math.h>
struct student
{
    char name[100];
    int roll,mark;
};
int main()
{
    FILE *f1,*f2;
    student s[100],temp;
    int i,j,n;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    n=0;
    while(fscanf(f1,"%s %d %d",s[n].name,&s[n].roll,&s[n].mark)!=EOF)
    {
        n++;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(s[j].mark>s[j+1].mark)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        fprintf(f2,"the information of %d student is:\n",i+1);
        fprintf(f2,"\t\t\t\t%s\n\t\t\t\t%d\n\t\t\t\t%d\n",s[i].name,s[i].roll,s[i].mark);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
