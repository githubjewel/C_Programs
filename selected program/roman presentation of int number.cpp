#include <stdio.h>
#include <math.h>
int main()
{
    int n,k,s,x,i;
    while(1)
    {
       scanf("%d",&n);
       k=log10(n)+1;
       if(k==4)
       {
           x=n;
           for(i=1; i<=3; i++)
           {
               s=x/10;
               x=x/10;
           }
           switch(s)
           {
               case 1: printf("M");
                 break;
                 case 2: printf("MM");
                 break;
           }
           n=n-(s*1000);
           k=log10(n)+1;
       }
       if(k==3&&n>0)
       {
           x=n;
           for(i=1; i<=2; i++)
           {
               s=x/10;
               x=x/10;
           }
           switch(s)
           {
                   case 1: printf("C");
                                 break;
                   case 2: printf("CC");
                                   break;
                   case 3: printf("CCC");
                                    break;
                   case 4: printf("CD");
                                break;
                     case 5: printf("D");
                 break;
                     case 6: printf("DC");
                 break;
                     case 7: printf("DCC");
                 break;
                     case 8: printf("DCCC");
                 break;
                     case 9: printf("CM");
                 break;
           }
           n=n-(s*100);
           k=log10(n)+1;


       }
       if(k==2&&n>0)
       {

           s=n/10;
           switch(s)
           {
                case 1: printf("X");
                 break;
                 case 2: printf("XX");
                 break;
                 case 3: printf("XXX");
                 break;
                 case 4: printf("XL");
                 break;
                 case 5: printf("L");
                 break;
                 case 6: printf("LX");
                 break;
                 case 7: printf("LXX");
                 break;
                 case 8: printf("LXXX");
                 break;
                 case 9: printf("XC");
                 break;
           }
           n=n-(s*10);
           k=log10(n)+1;


       }
       if(k==1&&n>0)
       {

           switch(n){
            case 1: printf("I");
                 break;
                 case 2: printf("II");
                 break;
             case 3: printf("III");
                 break;
             case 4: printf("IV");
                 break;
             case 5: printf("V");
                 break;
             case 6: printf("VI");
                 break;
             case 7: printf("VII");
                 break;
             case 8: printf("VIII");
                 break;
             case 9: printf("IX");
                 break;
           }
       }
   printf("\n");
    }

    return 0;
}
