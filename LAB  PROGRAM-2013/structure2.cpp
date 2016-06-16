#include <stdio.h>
#include <string.h>
int m=0;
int m1;
struct date
{
    int day;
    int month;
    int year;
};
struct info
{
  char firstname[20];
  char lastname[20];
  date date_of_birth;
  double cgpa;
}s[100];
void dateinsert()
{
    printf("Enter date of birth:");
      scanf("%d", &s[m1].date_of_birth.day);
     int  dd=s[m1].date_of_birth.day;
      scanf("%d", &s[m1].date_of_birth.month);
      int mm=s[m1].date_of_birth.month;
      scanf("%d", &s[m1].date_of_birth.year);
      int yy=s[m1].date_of_birth.year;
      if(s[m1].date_of_birth.year<1)
      {
          printf("invalid year\n");
      dateinsert();
      }
      else if(s[m1].date_of_birth.month<1 || s[m1].date_of_birth.month>12)
      {
          printf("invalid month\n");
      dateinsert();
      }
      else if((s[m1].date_of_birth.day < 1) || (s[m1].date_of_birth.day >31) ||(dd>30 && (mm==4 || mm==6 || mm==9 ||mm==11))|| (mm==2 && dd>29) || (mm==2 && dd>28 && (yy%4!=0 || (yy%4==0 && yy%100==0 && yy%400 != 0))))
    {
        printf("invalid date\n");
      dateinsert();
    }
}
void insert()
{
      printf("Enter first name:");
      scanf("%s", s[m].firstname);
      printf("Enter last name:");
      scanf("%s", s[m].lastname);
      m1=m;
     dateinsert();
       printf("Enter CGPA:");
        scanf("%lf", &s[m].cgpa);
        if(s[m].cgpa>4.00 || s[m].cgpa<0)  printf("invalid cgpa\n");
}
void del()
{
    int n,j;
    printf("which one do you want to delete?\n");
    scanf("%d", &n);
    if(n<=0 || n>m) printf("invalid\n");
    else
    {
    for(j=n;j<m;j++)
    {
        strcpy(s[j].firstname,s[j+1].firstname);
        strcpy(s[j].lastname,s[j+1].lastname);
        s[j].date_of_birth.day=s[j+1].date_of_birth.day;
        s[j].date_of_birth.month=s[j+1].date_of_birth.month;
        s[j].date_of_birth.year=s[j+1].date_of_birth.year;
        s[j].cgpa=s[j+1].cgpa;
    }
    }
}
void search()
{
    int j;
    char name[20];
    printf("enter first name:");
    scanf("%s",name);
    for(j=1;j<=m;j++)
    {
        if(strcmp(name,s[j].firstname)==0)
        break;
    }
    if(j>m) printf("not found\n");
    else
    {
        printf("%s\n", s[j].firstname);
        printf("%s\n", s[j].lastname);
        printf("%lf\n", s[j].cgpa);
        printf("%d ", s[j].date_of_birth.day);
        if(s[j].date_of_birth.month==1) printf("january %d", s[j].date_of_birth.year);
         if(s[j].date_of_birth.month==2) printf("february %d", s[j].date_of_birth.year);
          if(s[j].date_of_birth.month==3) printf("march %d", s[j].date_of_birth.year);
           if(s[j].date_of_birth.month==4) printf("april %d", s[j].date_of_birth.year);
            if(s[j].date_of_birth.month==5) printf("may %d", s[j].date_of_birth.year);
             if(s[j].date_of_birth.month==6) printf("june %d", s[j].date_of_birth.year);
              if(s[j].date_of_birth.month==7) printf("july %d", s[j].date_of_birth.year);
               if(s[j].date_of_birth.month==8) printf("august %d", s[j].date_of_birth.year);
                if(s[j].date_of_birth.month==9) printf("september %d", s[j].date_of_birth.year);
                 if(s[j].date_of_birth.month==10) printf("october %d", s[j].date_of_birth.year);
                  if(s[j].date_of_birth.month==11) printf("november %d", s[j].date_of_birth.year);
                   if(s[j].date_of_birth.month==12) printf("december %d", s[j].date_of_birth.year);
      printf("\n");
    }
}
void edit()
{
    printf("enter a serial number to edit\n");
    int j;
    scanf("%d", &j);
    printf("Enter first name:");
      scanf("%s", s[j].firstname);
      printf("Enter last name:teinsert()");
      scanf("%s", s[j].lastname);
      m1=j;
      dateinsert();
       printf("Enter CGPA:");
        scanf("%lf", &s[j].cgpa);
        if(s[j].cgpa>4.00 || s[j].cgpa<0)  printf("invalid cgpa\n");
}
void sort()
{
    int j, k, i;
   for(j=2; j<m+1;j++)
   for(k=m;k>=j;k--)
   {
       if(s[k-1].cgpa>s[k].cgpa)
       {
        s[77]=s[k-1];
        s[k-1]=s[k];
        s[k]=s[77];
       }

   }
   for(j=m,i=1;j>=1;j--, i++)
   {
       printf("%d. ", i);
      printf("%s\n", s[j].firstname);
   }
}
int main()
{
    int i;
    for(i=0;;)
    {
    int n;
    printf("What do you want to do?\n1. insert\n2. delete\n3. search\n4. edit\n5. show sorted list\n6. exit\n");
    scanf("%d",&n);
    if(n==1) {
        m++;
        insert();}
    else if(n==2) del();
    else if(n==3) search();
    else if(n==4) edit();
    else if(n==5) sort();
    else if(n==6) break;
    }
    return 0;
}
