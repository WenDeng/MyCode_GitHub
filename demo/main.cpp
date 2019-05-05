#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

//priority queue的底层容器是vector,其没有迭代器，
int main()
{
    int a[20]={1,2,3,4,5,5,6,7,8,9};
    vector<int> vec(a,a+11); 

    priority_queue<int> prique(vec.begin(),vec.end());

    prique.push(23);
    prique.push(24);
    cout<<"size: "<<prique.size()<<endl;
    while(!prique.empty())
    {
        cout<<prique.top()<<" ";
        prique.pop();
    }
    cout<<endl;
    return 0;
}