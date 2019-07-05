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
/**
默认比较函数为less, 大顶堆
**/
void defaultCmpLess() {
    cout << "=========defaultCmpLess(big heap)========" << endl;
    priority_queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;

}

/**
使用greater比较函数，小顶堆
**/
void useCmpGreater() {
    cout << "=========useCmpGreater(small heap)========" << endl;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;
}


//==========================

struct Node
{
    int x, y;
    Node(int a = 0, int b = 0):x(a), y(b){};
    friend bool operator<(const Node &a, const Node &b);

};
inline bool operator<(const Node &a, const Node &b) {
    if (a.x != b.x)  return a.x < b.x;
    return a.y > b.y;
}

/**
运算符重载
**/
void overloadOperator() {
    cout << "=========overload Operator< =========" << endl;
    cout << "a.x < b.x; a.y > b.y" << endl;
    priority_queue<Node> q;
    for (int i = 0; i < 10; i++) {
        q.push( Node( rand()%20, rand()%20 ) );
    }

    while (!q.empty()) {
        cout << q.top().x << "," << q.top().y << endl;
        q.pop();
    } 
    cout << endl;   
}


//=========================
/**
自构建比较函数
**/
struct cmp2
{
    bool operator()(int a, int b) {
        return a < b;
    }
};

void designCmp() {
    cout << "=========designCmp========" << endl;
    cout << "operator a<b" << endl;
    priority_queue<int, vector<int>, cmp2 > q;

    for (int i = 0; i < 10; i++) {
        q.push(rand()%20);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout <<endl;
}



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