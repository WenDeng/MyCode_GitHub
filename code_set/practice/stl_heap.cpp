#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
using namespace std;

//heap的底层还是vector
int main()
{
    int a[20]={1,2,3,4,5,5,6,7,8,9};
    vector<int> vec(a,a+11); 
    // make_heap(vec.begin(),vec.end(),less<int>()); //创建大根堆
    make_heap(vec.begin(),vec.end(),greater<int>()); //创建小根堆
    for(auto foo:vec) cout<<foo<<" ";
    cout<<endl<<endl;

    vec.push_back(11);
    // push_heap(vec.begin(),vec.end()); //插入元素后堆排
    make_heap(vec.begin(),vec.end()); //进行堆排序
    for(auto foo:vec) cout<<foo<<" ";
    cout<<endl;

    pop_heap(vec.begin(),vec.end());  //将跟节点值放入最后,一次排序
    for(auto foo:vec) cout<<foo<<" ";
    cout<<endl;
    vec.pop_back();

    sort_heap(vec.begin(),vec.end());  //从小到大排序
    for(auto foo:vec) cout<<foo<<" ";
    cout<<endl;


    return 0;
}