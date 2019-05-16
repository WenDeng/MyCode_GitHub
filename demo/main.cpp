#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    bool IsContinuous(vector<int> numbers) //求是否位顺子
    {
        if(numbers.size()!=5) return false;
        int count=0,sum=0,i,j;
        for(i=0;i<5;i++) //这里进行选择排序
        for(j=i+1;j<5;j++) if (numbers[i] > numbers[j])  swap(numbers[i], numbers[j]); 

        for(i=0;i<4;i++) 
        {
            if(numbers[i]==0) count++; //记录大小王的个数
            else if(numbers[i]==numbers[i+1]) return false;//如果有两值相等，肯定不行
            else sum+=numbers[i+1]-numbers[i]; //记录差之和
        }
        cout<<count<<"  "<<sum<<endl;
        if(sum<5 && (sum-count)<5) return true; 
        return false;
    }
};

int main()
{
    vector<vector<int> > ret;
    Solution solu;
    vector<int> data = {1, 2, 3, 0, 0};
    vector<int> data1 = {0, 0, 2, 1, 5};
    cout<<"result: "<<boolalpha<<solu.IsContinuous(data1)<<endl;
    return 0;
}