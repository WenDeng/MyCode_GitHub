
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//快拍算法比较常用，实现一下
int patition(vector<int> &vec,int start,int end)
{
    if(vec.size()==0) return -1;

    int i=start,j=end;
    int point=vec[i];
    while(i<j)//主要是注意边界条件就可以了
    {
        while(vec[j]>=point && j>i) j--;
        vec[i]=vec[j];

        while(vec[i]<=point && i<j) i++;
        vec[j]=vec[i];
    }
    vec[i]=point;
    return i;
}

void patitionSort(vector<int> &vec,int start,int end)
{
    //
    if(start<end)
    {
        int index=patition(vec,start,end);
        patitionSort(vec,start,index-1);
        patitionSort(vec,index+1,end);
    }
}

//快排算法可以用于寻找第k小的数，或这第k大的数，以及求出最小的k个数等...
int main()
{
    // int value[6]={3,1,6,10,2,5};
    int value[6]={1,1,1,3,2,2};
    vector<int> data(value,value+6);
    patitionSort(data,0,data.size()-1);
    // cout<<"patition result:"<<index<<endl;
    for(int i=0;i<data.size();i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return 0;
}