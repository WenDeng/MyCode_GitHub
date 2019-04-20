#include<iostream>
#include<sum.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<cstdlib>
#include<vector>
#include<array> //直接创建数组

using namespace std;

/**
 * @有多个整数，拼接这些整数，使得形成的数最大
 */
class Solution {
public:
    static bool compare(int a,int b)
    {
        string str_ab=to_string(a)+to_string(b);//这个函数是新知识点 atoi,itoa也可以了解一下
        string str_ba=to_string(b)+to_string(a);//string类的+操作
        return str_ab<str_ba;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res;
        int len=numbers.size();
        sort(numbers.begin(),numbers.end(),compare);//谓词-static
        for(auto foo: numbers) res+=to_string(foo); //合成一个字符串
        return res;
    }
};

int main(int argc,char *argv[])
{
    vector<int> vec={3,2,322,12,123,11};
    Solution solu;
    cout<<"result: "<<solu.PrintMinNumber(vec)<<endl;

    return 0;
}

// sort(value.begin(),value.end(),greater<int>());//由大到小排序
// make_heap(value.begin(),value.end(),greater<int>());
// sort(value.begin(),value.end(),less<int>());//默认由小到大排序
// sort(value.begin(),value.end(),[](int a,int b){ return a>b;});//用lambda表达式来实现谓词,由大到小排序
// set<int,less<int>>  set2={1,4,235,5};