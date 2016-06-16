#include<iostream>
#include<stack>
#include <stdio.h>

using namespace std;
int main()
{
stack<char> st;
char str[20000],ch;
int i,l,n,s;
scanf("%d%c",&n,&ch);
while(n--)
{
gets(str);
while(!st.empty())st.pop();
for(l=0;str[l];l++);
if(!l){printf("Yes\n");continue;}
if(l&1){printf("No\n");continue;}
for(i=0;i<l;i++)
{
switch(str[i])
{
case 40:
case 91:
st.push(str[i]);s=0;break;
case 41:
case 93:
s=1;
                if(st.empty()){s=0;i=l;continue;}
ch=st.top();
if((ch=='('&&str[i]==')')||ch=='['&&str[i]==']')
{
st.pop();
continue;
}
s=0;i=l;
break;
}
}
if(s)printf("Yes\n");
else printf("No\n");
}
return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int main() {
    int T; cin >> T;

    cin.ignore();
    while(T--) {
        string str; getline(cin, str);
        int counter=0;
        stack<char> S;
        bool stat = true;

        while(counter < str.length()) {
            if (str[counter] == '(' || str[counter] == '[')
                S.push(str[counter]);
            else if (str[counter] == ')') {
                if (S.empty() || S.top() != '(') {
                    stat = false; break;
                }
                else if (S.top() == '(')
                    S.pop();
            }
            else if (str[counter] == ']') {
                if (S.empty() || S.top() != '[') {
                    stat = false; break;
                }
                else if (S.top() == '[')
                    S.pop();
            }
            counter++;
        }

        if (stat && S.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
*/
# include <iostream>
# include <cstdio>
# include <cstring>
# define print  puts("No");
int main()
{
    int t,i,j,k,len;
    bool flag;
    char str[130],a[130],ch;
    scanf("%d%c",&t,&ch);
    for(k=0;k<t;k++)
    {
        flag  = false;
       gets(str);
       len = strlen(str);



             if(str[0]==')' || str[0]==']' || str[len-1]=='(' || str[len-1]=='[')
            {
                 print
                 continue;
            }


         if((len%2))
         print
         else
         {
         for(i=0,j=0;str[i];i++)
         {

           if(str[i]=='(' || str[i]=='[')
              a[j++]=str[i];
           else if(str[i]==')')
           {
               if(a[j-1]=='(')
                  j--;
               else
               {
                  flag = true;
                   break;
               }
           }
              else if(str[i]==']')
           {
               if(a[j-1]=='[')
                  j--;
               else
               {
                flag = true;
                  break;
               }
           }
         }
      if((!j && (a[j]=='[' || a[j]=='('))|| flag == false)
       puts("Yes");
     if(flag)
     print
         }

    }
    return 0;
}
/*
    #include<stdio.h>
    #include<string.h>
    int main()
    {
        char c,s[129],stack[129];
        int sp=-1,i,j,n,l,k;
        scanf("%d",&n);
        c=getchar();
        for(i=1;i<=n;i++)
        {
         sp=-1;k=0;
         while(1)
         {
          c=getchar();
          s[k++]=c;
          if(c=='\n' || c==EOF) {s[k]='\0';break;}
         }
         l=strlen(s);
         for(j=0;j<l;j++)
         {c=s[j];
         if(c=='[' || c=='(') stack[++sp]=c;
         else if(c==')') if(sp>=0 && stack[sp]=='(') sp--;
                         else break;
         else if(c==']') if(sp>=0 && stack[sp]=='[') sp--;
                         else break;
         }
         if(j==l && sp==-1) printf("Yes\n"); else printf("No\n");
        }
        return 0;
    }
    /*
    #include <cstdio>
#include <iostream>

using namespace std;

#define size 130
int top=0;

char stack[size];

void push(char ch)
{
        if( top==size ) return;
        top++;
        stack[top] = ch;
}

char pop()
{
        char ans;
        if( top == -1) return 0;
        ans = stack[top];
        top--;
        return ans;
}

void result(char* str)
{
        top = -1;
        int i=0;
        char ch;
        while( str[i] != 0 ) {
                switch( str[i] ) {
                case '(':       case '[':       push( str[i] );         break;
                case ')':
                        if( top==-1) {  printf("NO\n"); return;         }
                        ch = pop();
                        if( ch!= '(' ) { printf("NO\n"); return; }
                        break;
                case ']':
                        if( top==-1) {  printf("NO\n"); return;         }
                        ch = pop();
                        if( ch!= '[' ) { printf("NO\n");return; }
                        break;
                }
                i++;
        }
        if( top==-1 ) printf("YES\n");
        else    printf("NO\n");
}

int main()
{
        int n;
        int i,j;
        char str[130];
        cin >> n;
        char ch;
        cin.get(ch);
        for( i=0;i<n;i++ ) {
                cin.getline( str , size);
                result( str );
        }
        return 0;
}
