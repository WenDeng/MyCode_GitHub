#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//求最长递增子序列长度，可通过对应问题求出对应的解，但是不能求出最长子序列，比如 1 5 8 3 2
int countLength(vector<int> &serial)
{
    vector<int> temp;
    for(int i=0;i<serial.size();i++)
    {
        auto iter=lower_bound(temp.begin(),temp.end(),serial[i]);
        if(iter!=temp.end()) 
        {
            *iter=serial[i];
        }
        else temp.push_back(serial[i]);
    }
    return temp.size();
}

int main()
{
    vector<int> value1={};
    cout<<"The best length ascending serial's is:"<<countLength(value1)<<endl;
    vector<int> value1={1};
    cout<<"The best length ascending serial's is:"<<countLength(value1)<<endl;
    vector<int> value1={1,3,2};
    cout<<"The best length ascending serial's is:"<<countLength(value1)<<endl;    
    vector<int> value1={1,5,2,5,3,8,7,6,1,5};
    cout<<"The best length ascending serial's is:"<<countLength(value1)<<endl;
}