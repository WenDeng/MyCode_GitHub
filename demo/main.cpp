#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <list>
#include <cstring>
#include <functional>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.length()<=1) return s;//大小为1的字符串必为回文串

        string rev=s,ret,temp;
        reverse(rev.begin(),rev.end());//翻转字符串
        if(rev==s) return s;
        int len=0;//存放回文子串的长度
        for(int i=0;i<s.length();i++)//查找s与rev的最长公共子串
        {
            temp="";//存放待验证子串
            for(int j=i;j<s.length();j++)
            {
                temp+=s[j];//提取子串，每次增加一个字符
                if(temp.length()<len)  continue;//子串的长度不够....
                else if(rev.find(temp)!=-1)//在rev中找到temp
                {
                    string q=temp;//q用来验证temp是否是回文子串
                    reverse(q.begin(),q.end());
                    if(q==temp)
                    {
                        len=temp.length();
                        ret=temp;
                    }
                }
                else break;
            }
        }
        return ret;
    }
};


int main()
{
    Solution solu;
    cout<<"result:"<<solu.longestPalindrome("abbb")<<endl;
    cout<<"result:"<<solu.longestPalindrome("aacdefcaa")<<endl;
    cout<<"result:"<<solu.longestPalindrome("ohomm")<<endl;
    cout<<"result:"<<solu.longestPalindrome("asdfghnmzxcv")<<endl;
}