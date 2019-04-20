#include<iostream>
#include<vector>
using namespace std;
#define LENGTH 1000
class Solution {
public:
    int max(int va,int vb)
    {
        return va>vb?va:vb;
    }
    int rob(vector<int>& nums) {
        int length=nums.size();//获取长度
        if(length==0) return 0;
        if(length==1) return nums[0];
        if(length==2) return max(nums[0],nums[1]);
        if(length==3) return max(max(nums[0],nums[1]),nums[2]);//刚好有三户人家 
        
        //dp[0][i]记录偷窃 1 -- i 号房屋能取得的最大偷窃金额
        //dp[1][i]记录偷窃 2 -- i 号房屋能取得的最大偷窃金额
        int dp[2][LENGTH];
        dp[0][0] = nums[0];
        dp[0][1] = max(nums[0], nums[1]);
        dp[0][2] = max(dp[0][1], dp[0][0] + nums[2]);
        dp[1][1] = nums[1];
        dp[1][2] = max(nums[1], nums[2]);
        
        for(int i = 3; i < length; i++)
        {
            if(i != length - 1)
            {
                dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + nums[i]);
                dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + nums[i]);
            }
            else
            {
                dp[0][i] = max(dp[0][i - 1], dp[1][i - 2] + nums[i]);
            }
        }
        return dp[0][length - 1];
    }
};

int main()
{
    vector<int> nums;
    Solution solution;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout<<solution.rob(nums)<<endl;

    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(4);
    cout<<solution.rob(nums)<<endl;
}

// 下面已经是我觉得比较优的解了，但是还是得不到答案。
    // int rob(vector<int>& nums) {
    //     int length=nums.size();//获取长度
    //     if(length==0) return 0;
    //     if(length==1) return nums[0];
    //     if(length==2) return max(nums[0],nums[1]);
    //     if(length==3) return max(max(nums[0],nums[1]),nums[2]);//刚好有三户人家
        
    //     int i,va,vb,temp;
    //     int max_v=nums[0],mid=0,index,right;
        
    //     for(i=0;i<length;i++) //找到最大值的下标
    //         if(nums[i]>max_v) {  max_v=nums[i];mid=i;}

    //     right=(mid+1)%length;//最大值的右边家
    //     mid=0;


    //     for(i=0;i<length-3;i++)
    //     {
    //         mid++;
    //         index=(++right)%length;
    //         if(mid==1) vb=va=nums[index];
    //         else if(mid==2) vb=max(nums[index],va);
    //         else { temp=va;va=vb;vb=max(nums[index]+temp,vb); }
    //     }

    //     cout<<vb+max_v<<endl;
    //     return vb+max_v;
    // }


    //  int rob(vector<int>& nums) {
    //     int length=nums.size();//获取长度
    //     if(length==0) return 0;
    //     if(length==1) return nums[0];
    //     if(length==2) return max(nums[0],nums[1]);
    //     if(length==3) return max(max(nums[0],nums[1]),nums[2]);//刚好有三户人家
        
    //     int i,va,vb,temp;
    //     int max_v=-1,mid=-1,left,index,right,result1,result2;
        
    //     for(i=0;i<length;i++) //找到最大值的下标
    //     {
    //         left=(i-1)%length;
    //         right=(i+1)%length;
    //         if(nums[left]+nums[right]<=nums[i]) {  max_v=nums[i];mid=i; break;}
    //     }
    //     if(max_v!=-1)//找到最大值的情况
    //     {
    //         mid=0;
    //         for(i=0;i<length-3;i++)
    //         {
    //             mid++;
    //             index=(++right)%length;
    //             if(mid==1) vb=va=nums[index];
    //             else if(mid==2) vb=max(nums[index],va);
    //             else { temp=va;va=vb;vb=max(nums[index]+temp,vb); }
    //         }
    //         return vb+max_v;
    //     }

    //     //没找到最大值的情况
    //     {
    //         mid=0,right=1,max_v=nums[0];
    //         for(i=0;i<length-3;i++) //一定偷第一家
    //         {
    //             mid++;
    //             index=(++right)%length;
    //             if(mid==1) vb=va=nums[index];
    //             else if(mid==2) vb=max(nums[index],va);
    //             else { temp=va;va=vb;vb=max(nums[index]+temp,vb); }
    //         }    
    //         result1=vb+nums[0];

    //         mid=0,right=2,max_v=nums[1];
    //         for(i=0;i<length-3;i++) //一定偷第二家
    //         {
    //             mid++;
    //             index=(++right)%length;
    //             if(mid==1) vb=va=nums[index];
    //             else if(mid==2) vb=max(nums[index],va);
    //             else { temp=va;va=vb;vb=max(nums[index]+temp,vb); }
    //         } 
    //         result2=vb+nums[1];
    //         return max(result1,result2);
    //     }
    //  }