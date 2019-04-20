/*
* @bref: 解决八皇后问题-----联想解决正方体的填值问题
* @题目描述：八皇后指的是将八个皇后放到一个8X8的矩阵中，使得皇后之间不在同行或者同列、同对角线上。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int position[8]={0,1,2,3,4,5,6,7};//下标表示皇后所在的行，值表示皇后所在的列,定义可以保证不同行同列
    vector<int> vec(position,position+8);
    do{
        bool condition=true;
        //接下来，找出满足皇后之间不再对角线上排列，
        for(int i=0;i<8;i++)
        for(int j=i+1;j<8;j++)
        {
            if(i!=j && ((j-i)==(vec[i]-vec[j]) || (j-i)==(vec[j]-vec[i]))) { condition=false;}
            if(!condition) break;
        }
        if(condition)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    if(j==vec[i]) cout<<'+'<<" ";
                    else cout<<'*'<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

    }while(next_permutation(vec.begin(),vec.end()));
}