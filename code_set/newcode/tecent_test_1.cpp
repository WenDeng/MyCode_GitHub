/*
* @bref: 拼凑面额问题，用n种面额的硬币拼凑出1~m对应的面额
*/

//这是目前最好的思路，组成的面额依次增大，如果发现当前面额大于已取面额的总和，则需要再取一枚硬币，总和对应加上这枚硬币的值。
//升级一下，求出每种硬币对应个数
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> value;
vector<int> num;

int main()
{
    int n,m,sum=0,j,count;
    // cin>>m>>n;
    m=100;
    n=4;
    value.push_back(1);
    value.push_back(5);
    value.push_back(2);
    value.push_back(10);
    for(int i=0;i<n;i++)  num.push_back(0);//初始化为0

    sort(value.begin(),value.end());//排序

    for(int data=1;data<=m;data++)
    {
        count=0;
        if(data>sum) 
        {
            for(j=value.size()-1;j>=0;j--)
            {
                if(data>=value[j]) break; 
            }
            if(j==-1) return -1;//找不到合适的硬币
            sum+=value[j];
            num[j]++;
        }
        cout<<data<<":";
        for(int i=0;i<n;i++)
        {
            count+=num[i];
            if(num[i]>0) cout<<value[i]<<"-"<<num[i]<<" ";//输出面额，对应的每种的硬币的个数。
        }
        cout<<"  总硬币数："<<count<<endl;
    }
    
    return 0;
}






/*******************************************************************************
* @bref:这种思路是依次求出1~m种面额组成所需的最少硬币数，然后求出其最大值，即可求出
*       同时还需要考虑m恰好整除最大面额的情况。最后发现好像6到9的结果还是不对....
******************************************************************************
int value[101];
int minCount(int sum,int n)
{  
    if(sum==0) return 0;

    while(sum<value[n] ) 
    {
        n--;//找到能用的硬币
        if(n<0) break;//如果找不到能用的硬币
    }
    if(n<0) return -100;
    return sum/value[n]+minCount(sum%value[n],n);
}


int main()
{
    int m,n,i,max=0,result;
    cin>>m>>n;
    for(i=0;i<n;i++)
    {
        cin>>value[i];
    }

    for(i=1;i<=m;i++)
    {
        result=minCount(i,n-1);
        if(result<0) {cout<<-1<<endl;return 0;} //找不到合适的硬币
        if(result>max) max=result;
        if(i==m && m%value[n-1]==0) max+=1;
    }
    cout<<max<<endl;
    return 0;
}
*/