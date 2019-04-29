#include<deque>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    deque<int> data(8,3);//buffsize为512/4=128;
    deque<int>::iterator iter;
    cout<<iter._S_buffer_size()<<endl;
    return 0;
}