#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    Solution(){m_data=0;}
    Solution(int k):m_data(k){cout<<"constructor"<<endl;}
    Solution(Solution &so){cout<<"copy construcotr"<<endl; m_data=so.m_data;}

    string LeftRotateString(string str)
    {
        int i, j, index = 0, start = 0, len = str.length();
        cout<<"str length: "<<len<<endl;
        while(index<len && start<len) 
        {
            while(index<len && str[index]!=' ') index++;
            cout<<"start:"<<start<<" end:"<<index-1<<"    str:";
            for(i=start;i<index;i++) cout<<str[i];
            cout<<endl;
            for(i=start,j=index-1;i<j;i++,j--) swap(str[i],str[j]);//翻转每一个子字符串
            start=++index;//新的起始位置
        }

        for(i=0,j=len-1;i<j;i++,j--) swap(str[i],str[j]);
        return str;        
    } 
private:
    int m_data;
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
    for (char i = 0; i < 256; ++i)
    {
        printf("%d\n", i);
    }
    return 0;
}