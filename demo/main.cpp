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
    bool isNumeric(char *string)
    {
        //"+100","5e2","-123","3.1416"和"-1E-16"
        //12e","1a3.14","1.2.3","+-5"和"12e+4.3"
        if(string==nullptr||*string=='.') return false;
        bool hase=0,hasp;//记录e符合，记录小数
        if(*string=='+'||*string=='-') string++;//有正负号
        while(*string!='\0')
        {
            char last=*(string-1);//上一个字符
            if(*string<='9' && *string>='0') continue;
            else if(*string=='.')
            {
                if(hasp) return false;
                hasp = true;
                if(*(string-1)<='0'||*(string-1)>='9') return false;
                if(*(string+1)<='0'||*(string-1)>='9') return false; 
            }
            else if(*string=='e')
            {
                if(hase) return false;
                hase=true;
                if(last<='0'||last>='9') return false;
            }
            else if(*string=='+'||*string=='-')
            {
                if(last!='e') return false;
            }
            else return false;
            string++;
        }
        return true;        
    }
};
int main()
{
    Solution solu;
    if(solu.isNumeric("+100")) cout<<"isNumeric"<<endl;
    if(solu.isNumeric("5e2")) cout<<"isNumeric"<<endl;
    if(solu.isNumeric("-123")) cout<<"isNumeric"<<endl;
    if(solu.isNumeric("3.1416")) cout<<"isNumeric"<<endl;
    if(solu.isNumeric("-1E-16")) cout<<"isNumeric"<<endl;
    
    cout<<endl;
    if (solu.isNumeric("12e")) cout << "is Not Numeric" << endl;
    if (solu.isNumeric("1a3.14")) cout << "is Not Numeric" << endl;
    if (solu.isNumeric("1.2.3")) cout << "is Not Numeric" << endl;
    if (solu.isNumeric("+-5")) cout << "is Not Numeric" << endl;
    if (solu.isNumeric("12e+4.3")) cout << "is Not Numeric" << endl;

}