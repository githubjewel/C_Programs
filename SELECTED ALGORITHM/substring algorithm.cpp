#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
int test_case,t;
string a,b;
cin>>test_case;
cin.ignore(100,'\n');
while(test_case--)
{
getline(cin,a);
cin>>t;
cin.ignore(100,'\n');
while(t--)
{
getline(cin,b);
bool result=true;
if(b.size()>a.size())
result=false;

for (int i = 0, sz = b.size(); result && i < sz; i++)
{
if (a[i] != b[i])
{
result = false;
break;
}
}

if (result)
{
cout << "y" << endl;
}
else
{
cout << "n" << endl;
}
}
}
}
/*
#include<stdio.h>
#include<string.h>
struct z
{
 char s[100000];
} ar[1000];
int main()
{
 char t[100000];
 int i,j,k,q,c,tc;
 scanf("%d",&tc);
 for(c=1;c<=tc;c++)
 {
 scanf("%s",&t);
   scanf("%d",&q);
   for(k=0;k<q;k++)
   {
    scanf("%s",&ar[k].s);
    int l1=strlen(t),l2=strlen(ar[k].s),g=0;

      for(i=0,j=0;(i<l1 )&&(j<l2);i++)
      {
      if(ar[k].s[j]==t[i]){g+=i-j;
      j++;
     }
      }
     if(g==0 && j==l2)printf("y\n");
     else printf("n\n");
    }
   }
    return 0;

}
    #include<stdio.h>
    #include<string.h>
    int pi[100001],len_st,len_t;
    char st[100001],t[1001];
    void prefix_function()
    {
       int k=0,i;
       pi[0]=0;
       for(i=1;i<len_t;i++)
       {
          while(k>0&&t[k]!=t[i])
             k = pi[k];
          if(t[k]==t[i])
             k++;
          pi[i] = k;
       }
    }
    int main()
    {
       bool found;
       int i,n,c,j;
       scanf("%d%*c",&n);
       while(n--)
       {
          gets(st);
          len_st = strlen(st);
          scanf("%d%*c",&c);
          while(c--)
          {
             gets(t);
             len_t = strlen(t);
             prefix_function();
             j=0;found=0;
             for(i=0;i<len_st;i++)
             {
                while(j>0&&t[j]!=st[i])
                   j = pi[j];
                if(t[j]==st[i])
                   j++;
                if(j==len_t-1){found = 1; break;}
             }
             if(found)puts("y");
             else puts("n");
          }
       }
       return 0;
    }
    /*
    #include <iostream>
#include <string>
using namespace std;

int main(void) {
  int k, q;
  string a, b;

  cin >> k;
  cin.ignore(100, '\n');

  while (k--) {
    getline(cin, a);

    cin >> q;
    cin.ignore(100, '\n');

    while (q--) {
      getline(cin, b);

      bool result = true;

      if (b.size() > a.size())
        result = false;

      for (int i = 0, sz = b.size(); result && i < sz; i++) {
        if (a[i] != b[i]) {
          result = false;
          break;
        }
      }

      if (result) {
        cout << "y" << endl;
      } else {
        cout << "n" << endl;
      }
    }
  }

  return 0;
}
/*bool IsSubstring (string s, string t)
{
   for (int i = 0; i <= (s.Length - t.Length); i++)
   {
      bool found = true;

      for (int j = 0; found && j < t.Length; j++)
      {
         if (s[i + j] != t[j])
             found = false;
      }

      if (found)
         return true;
   }

   return false;
}
/*
01
#include <iostream>
02
using namespace std;
03

04
int main()
05
{
06
    char str1[] = "algorithm";
07
    char str2[] = "go";
08
    int count = 0;
09
    for(int i = 0; str1[i] != '\0'; i++)
10
    {
11
        bool foundNonMatch = false;
12
        for(int j = 0; str2[j] != '\0'; j++)
13
        {
14
            if (str1[i + j] != str2[j])
15
            {
16
                foundNonMatch = true;
17
                break;
18
            }
19
        }
20
        if (!foundNonMatch)
21
        count++;
22
    }
23
    if(count!=0)
24
    cout<<"YES string 2 is a substring of string 1\n";
25
    else
26
    cout<<"string 2 is NOT a substring of string 1\n";
27
}/*
01
public static boolean isSubstring (String s1, String s2)
02
    {
03
        if (s1 == null || s2 == null)
04
            throw new IllegalArgumentException("s1 or s2 is null");
05
        boolean substring = false;
06
        for(int i = 0; i < s2.length() - s1.length(); i++)
07
        {
08
            if (s2.substring(i, i + s1.length()) == s1)
09
            {
10
                substring = true;
11
            }
12
            else
13
            {
14
                substring = false;
15
            }
16
        }
17

18
        return substring;
19
    }
    /*#include <stdio.h>
#include <string.h>

int my_strstr( char const *s, char const *sub ) {
    char const *ret = sub;

    int r = 0;
    while ( ret = strchr( ret, *sub ) ) {
        if ( strcmp( ++ret, sub+1 ) == 0 ){
            r = 1;
        }
        else{
            r = 0;
        }
    }
    return r;
}

int main(int argc, char **argv){

    if (argc != 3) {
        printf ("Usage: check <string one> <string two>\n");
    }
    int result = my_strstr(argv[1], argv[2]);

    if(result == 1){
        printf("%s is a substring of %s\n", argv[2], argv[1]);
    } else{
        printf("%s is not a substring of %s\n", argv[2], argv[1]);
    }
    return 0;
}
/*char* StrStr(const char *str, const char *target) {
  if (!*target) return str;
  char *p1 = (char*)str;
  while (*p1) {
    char *p1Begin = p1, *p2 = (char*)target;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    if (!*p2)
      return p1Begin;
    p1 = p1Begin + 1;
  }
  return NULL;
}
