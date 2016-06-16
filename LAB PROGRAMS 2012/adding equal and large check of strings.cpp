#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class string
{
    private:
    char text[1000];
    public:
    void settext(char str[])
    {
        strcpy(text,str);
    }
    void gettext()
    {
        puts(text);
    }
    void stringcat(char str[])
    {
        strcat(text,str);
    }
    bool iseuqual(char str[])
    {
        if(strcmp(text,str)==0) return true;
        else return false;
    }
    bool isgreater(char str[])
    {
        if(strcmp(text,str)>0) return true;
        else return false;
    }
}var;
int main()
{
    char str[100];
    int n;

    while(1)
    {
        //cout("1.Settext\n2.Gettext\n3.strcat\n4.Equaltest\n5.length\npress 0 to exit\n");
        cin>>n;
        //gets(str);
        if(n==1)
        {
            cout<<"string\n";
            gets(str);
            var.settext(str);

        }
        else if(n==2) var.gettext();
        else if(n==3)
        {
            cout<<"string\rn";
            gets(str);
            var.stringcat(str);
        }
        else if(n==4)
        {
            cout<<"string\n";
            gets(str);
            if(var.iseuqual(str)) cout<<"yes\n";
            else
            cout<<"no\n";
        }
        else if(n==5)
        {
            cout<<"string\n";
            gets(str);
            if(var.isgreater(str)) cout<<"yes\n";
            else
            cout<<"n0\n";
        }
    }
}
