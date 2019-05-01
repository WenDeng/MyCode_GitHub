#include <deque>
#include <iostream>
#include <algorithm>
#include<vector>
#include <memory>
using namespace std;


int main()
{
    // deque<int> data(8, 3); //buffsize为512/4=128;
    // deque<int>::iterator iter;
    // cout << iter._S_buffer_size() << endl;
    // data.push_back(4);
    // data.push_front(1);
    // for(int foo:data) cout<<foo<<" ";
    // cout<<endl<<data[1]<<endl;
    int a=6;
    int &b=a;
    int c=b;
    cout<<a<<"  "<<c<<endl;
    vector<int> p,q;

    cout<<&a<<"   "<<&b<<endl<<endl;
    q.push_back(std::move(a));
    p.push_back(std::move(b));
    cout<<&p<<"  "<<&q<<"  "<<&p[0]<<"  "<<&q[0]<<endl;

    p=std::move(q);
    // cout<<q[0]<<endl;
    cout<<&q<<"  "<<&p<<"  "<<&q[0]<<"  "<<&p[0]<<endl;


    return 0;
}