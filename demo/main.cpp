#include<iostream>
#include<sum.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<cstdlib>
#include<array> //直接创建数组

using namespace std;

class Solution {
public:
    static bool compare(int a,int b)
    {
        string str_ab=to_string(a)+to_string(b);
        string str_ba=to_string(b)+to_string(a);
        return str_ab<str_ba;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res;
        int len=numbers.size();
        sort(numbers.begin(),numbers.end(),compare);//谓词-static
        for(auto foo: numbers) res+=to_string(foo);
        return res;
    }
};

int main(int argc,char *argv[])
{
    vector<int> vec={3,2,322,12,123,11};
    int N;
    cin>>N;
    int data[N]={1,2,3,4,5,7};
    for(auto foo:data) cout<<foo<<" ";
    cout<<endl;

    return 0;
}

// sort(value.begin(),value.end(),greater<int>());//由大到小排序
// make_heap(value.begin(),value.end(),greater<int>());
// sort(value.begin(),value.end(),less<int>());//默认由小到大排序
// sort(value.begin(),value.end(),[](int a,int b){ return a>b;});//用lambda表达式来实现谓词,由大到小排序
// set<int,less<int>>  set2={1,4,235,5};