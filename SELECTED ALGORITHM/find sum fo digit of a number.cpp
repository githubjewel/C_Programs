/*long long sum_of_digits(long long input) {
    long long total = input % 10;
    while ((input /= 10) != 0)
        total += input % 10;
    return total;
} *//*best way */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

long int Sum_of_Dig(long int Number)
{
    static long int sum=0;
    if (Number==0)
    {  return(sum);

    }
    else
    {
    sum=sum+Number%10+Sum_of_Dig(Number/10);
    }
    return(sum);
}

int main()
{
    long int Num=0,Sum_dig=0;
    printf("\n Enter Number : ");
    scanf("%ld",&Num);
    Sum_dig=Sum_of_Dig(Num);
    printf("\n Sum Of Digits :%ld  ",Sum_dig);
    return(0);

}
/*int digitSum(int a){
    static char tempStr[10];
    static int len, sum;
    int i;

    sum = 0;
    sprintf(tempStr,"%d",a);
    len = strlen(tempStr);
    for (i = 0; i < len; i++){
        sum += (tempStr[i] - '0');
    }

    return sum;
}*/
/*int getSum(int num){

    static int sum =0,r;

    if(num!=0){
      r=num%10;
      sum=sum+r;
      getSum(num/10);
    }

    return sum;
}
*/
#include<stdio.h>
int main(){
  long int num,sum=0,r;
  printf("Enter a number: ");
  scanf("%ld",&num);

  for(;num!=0;num=num/10){
      r=num%10;
      sum=sum+r;
  }
  printf("Sum of digits of number:  %ld",sum);
  return 0;
}
/*
while(num){
      r=num%10;
      num=num/10;
      sum=sum+r;
  }*/
  /*
  #include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int n,num,x,sum=0;
printf("Enter a number=");
scanf("%d",&n);
while(n>0)
{
x=n%10;
sum=sum+x;
n=n/10;
}
printf("Sum of digits of a number=%d",sum);
getch();
}*/
/*
You should also use an efficient algorithm to calculate the digit sum – try this one:

[c]int digit_sum(int number)

{ int sum = 0;
do
{
sum += number;
number /= 10;
sum -= number*10;
} while (number);
return sum;
}[/c] */
/*
int sum_digits(unsigned int n)
{
    int c;
    int sum = 0;
    n = (n * TEN_OVER_10000)>>9; // n*10/10000 Q16
    for (c=0;c<4;c++)
    {
    printf("Digit: %d\n", n>>16);
        sum += n>>16;
        n = (n & 0xffff) * 10; // next digit
    }
    return sum;
}
int main()
{
    unsigned long n,a;
    scanf("%lu",&n);
    printf("%lu\n",sum_digits(n));
    return 0;
}
*/-= 48 * BigNumberStr.Length;
