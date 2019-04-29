#include <deque>
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;


int main()
{
    deque<int> data(8, 3); //buffsize为512/4=128;
    deque<int>::iterator iter;
    cout << iter._S_buffer_size() << endl;
    data.push_back(4);
    data.push_front(1);
    for(int foo:data) cout<<foo<<" ";
    cout<<endl<<data[1]<<endl;

    return 0;
}