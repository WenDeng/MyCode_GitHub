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
    Solution(){cout<<"constructor function!"<<endl;}
    void operator[](int n) {cout<<"velue: "<<n<<endl;}
    void test(Solution t){ cout<<"test"<<endl;}
    void func()
    {
        test(Solution());//这里相当于通过类名创建了一个临时对象
        cout << "hello world" << endl;
    }
};



int main(int argc,char *argv[])
{
    Solution solu;

    solu[6];
    return 0;
}

// sort(value.begin(),value.end(),greater<int>());//由大到小排序
// make_heap(value.begin(),value.end(),greater<int>());
// sort(value.begin(),value.end(),less<int>());//默认由小到大排序
// sort(value.begin(),value.end(),[](int a,int b){ return a>b;});//用lambda表达式来实现谓词,由大到小排序
// set<int,less<int>>  set2={1,4,235,5};