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

class Solution {
public:
    int StrToInt(string str)
    { //返回值为0的几种情况区分，正负号、值范围保证2147483647~-2147483648，
        if(str.length()==0) return 0;
        int result=0,i,state=1;

        if(str[0]<='9'&&str[0]>='0') result=result*10+str[0]-'0';
        else if(str[0]=='+')  state=1;
        else if(str[0]=='-')  state=-1;
        else return 0;

        for(i=1;i<str.length();i++)
        {
            if(str[i]>='0'&&str[i]<='9') result=result*10+str[i]-'0';
            else return 0;
        }

        return state==-1?-result:result;
    }
};

int main()
{
    // string str("wen deng am I");
    // Solution solu;
    // cout<<solu.LeftRotateString(str)<<endl;
    // vector<int> vec={1,3,5,6,7,4,8};
    // sort(vec.begin,vec.end(),less<int>());
    // for(auto foo:vec) cout<<foo<<" ";
    // cout<<endl;
    Solution solu;
    int n=10;
    cout<<"sum: "<<solu.StrToInt("d3234")<<endl;
    cout << "sum: " << solu.StrToInt("-321") << endl;
    cout << "sum: " << solu.StrToInt("+321") << endl;
    return 0;
}