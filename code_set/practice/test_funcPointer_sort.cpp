#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class Test
{
public:
    Test(){
        static int i = 0;
        cout<<"Test()"<<":"<<i++<<endl;
    }
    ~Test(){
        static int i = 0;
        cout<<"~Test()"<<":"<<i++<<endl;
    }
};

int (*compare)(int a,int b);

template<typename T>
int comparetest(T a,T b)
{
    return a>b;
}


int main()
{
   int value[10]={1,2,3,4,5,5,4,4,5,6};
   vector<int> data={1,2,3,4,5,5,4,4,5,6};
   compare=&comparetest;
   sort(value,value+10,compare);//测试数组排序
//    sort(data.begin(),data.end(),*compare);//测试数组排序

//    sort(data.begin(),data.end());//测试数组排序
   for(auto foo:value) cout<<foo<<" ";
   cout<<endl;
    for(auto foo:data) cout<<foo<<" ";
    // int a[n]={1,2,3,4};

}