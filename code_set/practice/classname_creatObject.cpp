#include <iostream>
#include <sum.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <array> //直接创建数组

using namespace std;

class Solution
{
  public:
    Solution() { cout << "constructor function!" << endl; }
    // Solution operator() {Solution temp;return temp;}
    void test(Solution t) { cout << "test" << endl; }
    void func()
    {
        test(Solution()); //这里相当于通过类名创建了一个临时对象
        cout << "hello world" << endl;
    }
};

int main(int argc, char *argv[])
{
    Solution solu;

    solu.func();
    return 0;
}
