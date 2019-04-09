/*
* @bref: 怪兽与金币
*/

#include<iostream>
#include<algorithm>
using namespace std;
long long power[51];
int gold[51];

int minNeedGold(int n,int start,long long quist,long long *pow,int *gd)//怪兽个数、拳头值、怪兽武力、怪兽金币
{
    if(start>=n) return 0;
    if(quist<pow[start]) //打不过，收买
    {
        quist+=pow[start];
        return gd[start]+minNeedGold(n,start+1,quist,pow,gd);
    }
    
    //打得过，可收买或者不收买,取最小值 (可以优化，比如如果怪兽的金币为2则直接打，为1的时候才考虑收买或者不收买)
    return min(gold[start]+minNeedGold(n,start+1,quist+pow[start],pow,gd),minNeedGold(n,start+1,quist,pow,gd));
}

int main()
{
    int N,i;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>power[i];
    }
    for(i=0;i<N;i++)
    {
        cin>>gold[i];
    }
    
    cout<<minNeedGold(N,0,0,power,gold);

    return 0;
}