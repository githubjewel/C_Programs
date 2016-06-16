#include <stdio.h>
struct student_info
{
    char name[100];
    int id;
    double cgpa;
}s[15],p[15];
int main()
{
    int i;
    char b[10];
    FILE *fp;
    fp=fopen("info.txt", "w");
    for(i=0;i<5;i++)
    {
        gets(s[i].name);
        scanf("%d %lf", &s[i].id, &s[i].cgpa);
        gets(b);
    }
    fwrite(s,sizeof(student_info),10, fp);
    fclose(fp);
    fp=fopen("info.txt", "r");
    fread(p,sizeof(student_info),10, fp);
    for(i=0;i<5;i++)
    {
        printf("%s\n", s[i].name);
        printf("roll: %d\nCGPA: %.2lf\n",s[i].id, s[i].cgpa);
    }
    return 0;
}
