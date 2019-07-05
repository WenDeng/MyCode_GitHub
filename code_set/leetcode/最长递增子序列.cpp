//https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1031/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        // 动态规划+二分查找求解
        // （1）先将信封进行排序，主键宽度由小到大，为了方便二分查找，高度由大到小
        // （2）用二分法依次从前往后求出每个信封对应的最大套数（对应为最大递增子序列）
        if(!envelopes.size()) return 0;
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &va1,vector<int> &va2){
            if(va1[0]==va2[0]) return va1[1]>va2[1]; //保证前面的大值被后面的小值冲掉，相当于消除了宽相等而高较大的值
            return va1[0]<va2[0];} //用lamda表达式实现了函数
        );//进行排序

        int envsize=envelopes.size(),len=0;
        vector<int> envque(envsize,0);
        for(int i=0;i<envsize;i++)
        {
            int temp=envelopes[i][1];
            auto iter=lower_bound(envque.begin(),envque.begin()+len,temp); //这个算法用的是二分查找，寻找第一个不小于temp的迭代
            if(iter==(envque.begin()+len)) envque[len++]=temp;
            else *iter=temp;
        }

        return len;
    }
};