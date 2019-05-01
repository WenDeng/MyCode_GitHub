#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int value[10] = {1, 2, 3, 4, 5, 5, 4, 4, 5, 6};
    vector<int> data1 = {1, 2};
    vector<int> data2 = {1, 3, 4, 5, 4, 3, 5, 2};
    vector<int> data3 = {1, 2, 3, 4, 5, 4, 3, 5};

    int k = 6, s = 7;
    k = static_cast<int &&>(s);
    cout << k << " " << s << endl;

    cout << endl
         << "对POD类型的数据进行move,不会改变其值!!" << endl;
    k = std::move(s);
    cout << k << " " << s << endl;

    cout << endl
         << "对非POD类型的数据进行move,会改变括号里的值!!" << endl;
    // data1 = std::move(data2);
    // data1 = std::move(data3);
    data1 = static_cast<vector<int> &&>(data2);

    cout << endl
         << "after move:" << endl
         << "data1:";
    for (int foo : data1)
        cout << foo << " ";

    cout << endl
         << "data2:";
    for (int foo : data2)
        cout << foo << " ";

    cout << endl
         << "data3:";
    for (int foo : data3)
        cout << foo << " ";
    cout << endl;

    int m = 3, n = 5;
    int *p = &m, *q = &n;
    p = std::move(q);
    cout << *p << " " << *q << endl;

    return 0;
}