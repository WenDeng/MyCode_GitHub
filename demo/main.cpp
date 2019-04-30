#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        //也不知道是谁想到的这种方法，反正很牛逼
        int result=0,k=1;
        if(data.size()&1==1) return;//单数个数表示不合法
        
        for(auto foo:data) result^=foo;
        while(!(result&k)) k=k<<1;//找到result不为0的最低位
        
        if(!result) return;//表示所有的数都是成对出现的，也不合法
        for(auto foo:data) 
        {
            if(foo&k) *num1= (*num1)^foo;//对应位为1
            else *num2= (*num2)^foo;//对应为0
        }
    }
};
int main()
{
   int value[10]={1,2,3,4,5,5,4,4,5,6};
   vector<int> data={1,2,3,4,5,4,3,5};
//    vector<int> data={1,2};
//    vector<int> data={1,3,4,5,4,3,5,2};
   int res1=0,res2=0;
   Solution sol;
   sol.FindNumsAppearOnce(data,&res1,&res2);
   cout<<res1<<" "<<res2<<endl;
   return 0;
}