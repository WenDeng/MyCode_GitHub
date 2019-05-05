#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <queue>
#include <slist>

using namespace std;

//priority queue的底层容器是vector,其没有迭代器，
int main()
{
    int a[20]={1,2,3,4,5,5,6,7,8,9};
    vector<int> vec(a,a+11); 

    //优先级队列
    priority_queue<int> prique(vec.begin(),vec.end()); //优先级队列
    prique.push(23);
    prique.push(24);
    cout<<"priority queue size: "<<prique.size()<<endl;
    while(!prique.empty())
    {
        cout<<prique.top()<<" ";
        prique.pop();
    }
    cout<<endl;

    //单向链表
    slist<int> slst;
    cout<<"slist size: "<<slst.size()<<endl;

    return 0;
}