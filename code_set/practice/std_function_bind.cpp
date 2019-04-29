#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
using typeFunc = std::function<void(vector<int> &)>; //定义函数类型

class Test
{
public:
    void show(vector<int> &data)
    {
        for (int foo : data)
            cout << foo << " ";
        cout << endl;
    }
};

int main()
{
    Test test;
    int array[] = {1, 2, 3, 4, 5};
    typeFunc func = bind(&Test::show, test, std::placeholders::_1);
    vector<int> data(5); //初始化空间容量为5，默认值为0
    vector<int> data1 = {1, 2, 3, 4, 5};
    vector<int> data2(5, 3);             //初始化空间为5，值为3
    vector<int> data3(array, array + 5); //初始化空间为5，值为3
    func(data);
    func(data2);
    func(data3);
}