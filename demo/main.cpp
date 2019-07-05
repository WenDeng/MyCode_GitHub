#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <memory>
#include <sstream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <cstring>
#include <functional>
using namespace std;

class LRUCache
{
private:
    int m_capacity;
    unordered_map<int,list< pair<int,int> >::iterator > position;//主要是用来定位key在链表的对应位置
    list<pair<int,int>> cache; //用来缓存放入的数据对
public:
    LRUCache(int capacity):m_capacity(capacity){}

    int get(int key)
    {
        if(position.find(key)!=position.end()) //若缓存中已经存在该数据
        {
            put(key,position[key]->second);
            return position[key]->second; 
        }
        return -1; //缓存中不存在该数据
    }

    void put(int key, int value)
    {
        if(position.find(key)!=position.end())  cache.erase(position[key]); //如果已经存在，则早期版本删除
        else if(cache.size()>=m_capacity) //容量达到上线，需要空出一个位置
        {
            position.erase(cache.back().first);//将对应的迭代器移除，避免后期复用
            cache.pop_back();
        }
        cache.push_front(pair<int,int>(key,value));
        position[key]=cache.begin();//设定key对应的迭代器
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache obj(3);
    cout<<obj.get(1)<<endl;
    obj.put(1, 2);
    obj.put(3, 3);
    obj.put(4, 4);
    cout<<obj.get(3)<<endl;
    obj.put(5,6);
    cout<<obj.get(1)<<endl;
    cout<<obj.get(3)<<endl;
    cout<<obj.get(4)<<endl;
    cout<<obj.get(5)<<endl;
}
