#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include <map>

using namespace std;

int main()
{
    cout << "set usage-------------------------------" << endl;
    int value[5] = {1, 2, 3, 4, 5};
    set<int> data(value, value + 5);
    data.insert(3);
    data.erase(4);
    set<int>::iterator iter = data.begin();
    for (; iter != data.end(); iter++)
        cout << *iter << " ";

    iter = data.find(5); //使用这个函数比使用STL的find函数更有效率
    cout << *iter << endl;
    // *iter=9;//企图通过迭代器修改set元素是不被允许的

    std::shared_ptr<int> ptr = shared_ptr<int>(new int(6));
    cout << sizeof(ptr) << endl;

    return 0;
}
