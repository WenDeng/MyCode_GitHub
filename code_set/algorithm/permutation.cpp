/*
* @bref:实现全排列算法，用于对给定数字或字符串进行全排列，并输出对应的结果。
* @application: 八皇后问题、组合、排列
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace  std;

static int gCount=0;

template<typename T>
void permutation(T *value,int start,int end) //目前实现的代码对于有重复数字的结果还是不能处理
{
    if(start==end) //结束
    {
        gCount++;
        for(int i=0;i<end;i++)
        {
            cout<<value[i];
        }
        cout<<endl;
    }
    
    //没有结束，继续处理
    for(int i=start;i<end;i++)
    {
        T temp;
        if(i!=start && value[i]==value[start]) continue;//排列组合中，如果两值相同，不用交换,其实还是不能去重，去重的话可能用map会更好。
        temp=value[start];//交换
        value[start]=value[i];
        value[i]=temp;

        permutation(value,start+1,end);
        
        temp=value[start];//还原
        value[start]=value[i];
        value[i]=temp;
    }
}

int main()
{
    int str[5]={1,2,3,4,5};
    vector<int> vec(str,str+5);
    gCount=0;
    //下面用我自己实现的函数来处排列问题
    // permutation(str,0,5);
    // cout<<endl<<"result: "<<gCount<<endl;
 
    //接下来用STL中的函数来解决排列问题
    // do{
    //     cout<<++gCount<<":";
    //     for(auto it=vec.begin();it<vec.end();it++)
    //     cout<<*it;
    //     cout<<endl;
    // }while(next_permutation(vec.begin(),vec.end()));

    //接下来用STL中的函数来解决组合问题，这里假设求从上述str中取3个数的组合情况
    vector<int> element;
    element.push_back(1);
    element.push_back(1);
    element.push_back(1);
    element.push_back(0);
    element.push_back(0);
    do{
        cout<<++gCount<<":";
        for(int it=0;it<vec.size();it++) //cout<<element[it];
        if(element[it]==1) cout<<vec[it];//为1时输出
        cout<<endl;
    }while(prev_permutation(element.begin(),element.end()));//全排列非字典序

    return 0;
}
