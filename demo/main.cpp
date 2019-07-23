#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <memory>
#include <sstream>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <list>
#include <cstring>
#include <functional>
#include<unordered_map>
using namespace std;


//求解抖音网络红人人数
//目前的思路是用一个二维数组存储，一维数组上的每位表示对应的人是否关注他
//此外还需要一个栈来进行深度遍历，表示关注当前人的人，并且需要访问对应维度上的人，将其加入当前用户的关注人群。
int findTheAllNetStar(int n,int m, vector<pair<int,int>> &pp) //人数、关注对数、关注对
{
    vector<vector<int>> watchTable(n,vector<int>(n,0));//初始化一个n维数组，每一个值位vector<int>(n,0),即也是一个n维数组，且都为0

    for(int k=0;k<m;k++)
    {
        int i=pp[k].first-1,j=pp[k].second-1;
        watchTable[j][i]=1; //i关注了j
    }

    for(int i=0;i<watchTable.size();i++)
    {
        for(int j=0;j<watchTable.size();j++)
        cout<<watchTable[i][j]<<" ";
        cout<<endl;
    }

    for(int k=0;k<n;k++) //深度遍历求出每个用户的间接关注表
    {   
        cout<<endl<<"user number:"<<k<<"    遍历用户："; //----------------
        static stack<int>  temp;//遍历栈
        for(int t=0;t<n;t++)
        {
            if(t!=k && watchTable[k][t]==1) temp.push(t); 
        }
        while(!temp.empty())
        {
            int index=temp.top();
            cout<<index<<" "; //---------------------------------------
            temp.pop();
            if(watchTable[k][index]==2) continue;//index用户已经遍历过，不再遍历
            else //没有遍历过，需要遍历index用户的关注表
            {
                watchTable[k][index]=2;
                for(int t=0;t<n;t++) //遍历index的关注列表，获取其中未关注k的人
                {
                    if(t!=k && watchTable[index][t]==1 && watchTable[k][t]==0) //t关注了index，t还没加入k的关注列表，那就添加
                    {
                        watchTable[k][t]=1; //添加
                        temp.push(t);//将t加入遍历栈
                    }
                }
            }
        }
    }
        
    cout<<endl;
    for(int i=0;i<watchTable.size();i++)
    {
        for(int j=0;j<watchTable.size();j++)
        cout<<watchTable[i][j]<<" ";
        cout<<endl;
    }

    int count=0;//用来记录网红人数
    for(int i=0;i<n;i++)
    {
        bool state=true;
        for(int j=0;j<n;j++)
        {
            if(i!=j && watchTable[i][j]==0) {state=false;break;}
        }
        if(state) count++;
    }
    return count;
}


//思路：这个题跟LRU有点类似
class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> m_value; //存键值对
    stack<int> m_max; //存最大值
    stack<int> m_min; //存最小值

    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) 
    {
        if(m_value.find(key)!=m_value.end())  m_value[key]++;
        else m_value[key]=1;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) 
    {
        if(m_value.find(key)==m_value.end()) return;
        if(m_value[key]<=1) m_value.erase(key);
        else m_value[key]--;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() 
    {
        if()
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() 
    {
        
    }
};

int main()
{  
    //
    MinStack minstack;
    minstack.push(1);
    minstack.push(2);
    cout<<"top:"<<minstack.top()<<endl;
    cout<<"min:"<<minstack.getMin()<<endl;
    minstack.pop();
    cout<<"top:"<<minstack.top()<<endl;
    cout<<"min:"<<minstack.getMin()<<endl;
    minstack.pop();
    cout<<"top:"<<minstack.top()<<endl;
    cout<<"min:"<<minstack.getMin()<<endl;
}

