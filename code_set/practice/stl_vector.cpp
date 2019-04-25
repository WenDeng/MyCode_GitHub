#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    vector<int> data(5);//初始化空间容量为5，默认值为0
    vector<int> data1={1,2,3,4,5};
    vector<int> data2(5,3);//初始化空间为5，值为3

    vector<int>::iterator iter=find(data1.begin(),data1.end(),2);
    cout<<data1.front()<<" "<<data1.back()<<endl;//获取第一个和最后一个值
    cout<<*data1.begin()<<" "<<*data1.end()<<endl; //获取迭代器，并取值
    data1.push_back(6);//放入值
    data1.pop_back();//删掉最后一个元素，void返回
    data1.erase(data1.end());//删除指定迭代器的值
    data1.resize(20);//从新设置存值空间，默认初始为0
    data1.clear();//清楚全部内容
}