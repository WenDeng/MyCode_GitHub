#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int data[]={1,2,3,4,5,5};
    list<int> lst2(data,data+5);//可以这样初始化链表
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(3);
    lst.pop_front();
    // lst.pop_back();


    list<int>::iterator iter=find(lst.begin(),lst.end(),2);
    lst2.splice(iter,lst.begin,lst.end());//将lst链表拼接到lst2中
    lst2.reverse();//反转链表
    lst2.sort();//排序链表的元素
    lst.insert(iter,5);//插入值
    lst.insert(lst.end(),2);
    lst.remove(2);//移除所有值为2的节点
    lst.unique();//移除所有连续而相同的元素，只保留连续相同部分的第一个元素
    lst.empty(); //判断是否为空

    cout<<lst.front(); //获取头结点的元素值
    cout<<lst.back();  //获取尾节点的元素值
    cout<<lst.size();  //元素个数
}

