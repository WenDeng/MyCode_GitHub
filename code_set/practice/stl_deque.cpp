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
    data.pop_back();
    data.push_front(1);
    data.pop_front();
    data.erase(data.begin());
    data.erase(data.begin(), data.end());
    data.insert(data.begin(), 4);
    data.clear();
    for (int foo : data)
        cout << foo << " ";
    cout << endl
         << data[1] << endl;

    return 0;
}