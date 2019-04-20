#include<iostream>
#include<sum.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<cstdlib>
#include<array> //直接创建数组

using namespace std;

/*
* @bref:输入一个N,求1~N中的1的个数
*/
class Solution {
public:
    int powerBase10(int n)
    {
        int k=1;
        for(int i=1;i<=n;i++) k=k*10;
        return k;
    }
    int count_numOf1(char *str)
    {
        int length=strlen(str),num1=0,num2,num3;
        int first=*str-'0';
        if(length==0) return 0;
        if(length==1 && first>=1) return 1;
        if(length==1 && first<1)  return 0;

        if(first>1) num1=powerBase10(length-1);
        if(first==1) num1=atoi(str)-powerBase10(length-1)+1;

        num2=first*(length-1)*powerBase10(length-2);
        num3=count_numOf1(str+1);

        return num1+num2+num3;  
    }

    //求1到n范围内的整数中1的个数
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count=0;
        //将数字转为字符串
        char *str=new char[10];
        sprintf(str,"%d",n);

        count=count_numOf1(str);
        delete str;
        return count;
    }
};

int main(int argc,char *argv[])
{
    int n;
    cin>>n;
    Solution solu;
    cout<<endl<<"N="<<n<<"     result: "<<solu.NumberOf1Between1AndN_Solution(n)<<endl;

    return 0;
}

// sort(value.begin(),value.end(),greater<int>());//由大到小排序
// make_heap(value.begin(),value.end(),greater<int>());
// sort(value.begin(),value.end(),less<int>());//默认由小到大排序
// sort(value.begin(),value.end(),[](int a,int b){ return a>b;});//用lambda表达式来实现谓词,由大到小排序
// set<int,less<int>>  set2={1,4,235,5};