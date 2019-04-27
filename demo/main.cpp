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
        for(auto foo:data) result^=foo;
        while(!(result&k)) k=k<<1;//找到result不为0的最低位

        int i=0,j=data.size()-1;
        while(i<j)
        {
            while(data[i]&k) i++;//找到第一个最低为不为1的数的下标
            while(!(data[j]&k)) j--;//找到第一个最低为不为0的数的下标
            if(i<j)
            { 
                swap(data[i],data[j]);//交换
                i++;j--;
            }
        }
        int t=i-1;
        while(t>=0) *num1= (*num1)^data[t--];//前面部分
        while(i<data.size()) *num2= (*num2)^data[i++];//后面部分
    }
};


int main()
{
   int value[10]={1,2,3,4,5,5,4,4,5,6};
//    vector<int> data={1,2,3,4,5,4,3,5};
//    vector<int> data={1,2};
   vector<int> data={1,3,4,5,4,3,5,2};
   int res1=0,res2=0;
   Solution sol;
   sol.FindNumsAppearOnce(data,&res1,&res2);
   cout<<res1<<" "<<res2<<endl;
   return 0;
}