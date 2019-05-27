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
        int i=0,j=0;
        char temp;
        while(*str!='\n' && *pattern!='\n')
        {
            if(*pattern=='.') //任意字符
            {
                cout<<".字符出现"<<endl;
                str++, pattern++;
                
            }
            else if(*pattern=='*')
            {
                cout << "*字符出现" << endl;
                temp = *str;//记录下这个出现任意次的字符
                while(*str==temp) 
                {
                    if(match(str,pattern+1)) return true;
                    else str++;
                }
            }
            else if(*str!=*pattern) return false;
            str++,pattern++;
        }
        if(*str=='\n' && *pattern=='\n') return true;
        return false;
    }
};
int main()
{
    Solution solu;
    if(solu.match("aaa","a.a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;

    if(solu.match("aaa","ab*ac*a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;

    if(solu.match("aaa","aa.a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;

    if(solu.match("aaa","ab*a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl<<endl;
}