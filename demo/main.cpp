#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <list>
#include <functional>
using namespace std;

#include <iostream>
#include <memory>
using namespace std;

class Solution
{
public:
    bool match(char *str, char *pattern)
    {
        char *p=str,*q=pattern;
        while(*p!='\n') cout<<*(p++);
        cout<<endl;
        while(*q!='\n') cout<<*(q++);
        cout<<endl;


        char temp;
        while(*str!='\n' && *pattern!='\n')
        {
            if(*pattern=='.') str++, pattern++;//任意字符
            if(*(pattern+1)=='*')
            {
                temp = *pattern;//记录下这个出现任意次的字符
                while(*str==temp) 
                {
                    if(match(str,pattern+2)) return true;
                    else str++;
                }
                pattern+=2;
            }
            else if(*str==*pattern) str++,pattern++;
            else { cout<<*str<<"!="<<*pattern<<endl;return false;}
            
        }
        if(*str=='\n' && *pattern=='\n') return true;
        return false;
    }
};
int main()
{
    Solution solu;
    if(solu.match("aaa\n","a.a\n")) cout<<"match success!!"<<endl<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;

    if(solu.match("aaa\n","ab*ac*a\n")) cout<<"match success!!"<<endl<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;

    if(solu.match("aaa\n","aa.a\n")) cout<<"match success!!"<<endl<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;

    if(solu.match("aaa\n","ab*a\n")) cout<<"match success!!"<<endl<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;
}