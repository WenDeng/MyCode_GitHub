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
        while(*str!='\n' && *pattern!='\n')
        {
            if()
        }
        if(*str=='\n' && *pattern=='\n') return true;
        return false;
    }
};
int main()
{
    Solution solu;
    if(solu.match("aaa","a.a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl;

    if(solu.match("aaa","ab*ac*a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl;

    if(solu.match("aaa","aa.a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl;

    if(solu.match("aaa","ab*a")) cout<<"match success!!"<<endl;
    else cout<<"match fail!!!!"<<endl;
}