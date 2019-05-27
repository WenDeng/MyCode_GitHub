#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

/* c++中之所以要进行细分成四种转换，主要原因是提供标识符号，以便于代码排查和检视，同时也能支持不同转换需求 */

//static_cast:用于类层次结构中基类和派生类之间指针或引用的转换,用于基本数据类型之间的转换，
//主要用于代替C中通常的转换操作,隐式转换都建议使用static_cast进行标明和替换

//dynamic_cast：只有在派生类之间转换时才使用dynamic_cast，type-id必须是类指针，类引用或者void*。
//dynamic_cast要求基类必须有虚函数，因为其是运行时类型检查，需要运行时类型信息（虚表），dynamic_cast下行转换是安全的，类型不一致是转为空指针。

//const_cast：常量指针和非常量指针之间的互转，常量引用和非常量引用之间的互转,去除常量性是一个危险的动作，尽量避免使用。

//reinterpret_cast:不到万不得已，不使用这个转换，高危操作。其能从底层对数据进行重新解释
//reinterpret_cast可以实现很多强转，包括整型和指针，指针和数组，指针和引用等。

class Base
{
public:
    virtual ~Base(){};

private:
    int m_a;
};

class Derived : public Base
{
public:
private:
    int m_b;
    int m_c;
};

int main()
{
    Base base1;
    int b = static_cast<double>(3.14);
    Derived *der1 = dynamic_cast<Derived *>(&base1); //必须有虚函数，才有运行时类型
    if (der1 == nullptr)
        cout << "type is not consistent!!!,nullptr......." << endl;

    int a[5] = {1, 2, 3, 4, 5};
    int const *p = a;
    int *q = const_cast<int *>(p); //将const转为非const
    q[1] = 6;
    cout << "a[1] value:" << *(++q) << endl;

    int *s = reinterpret_cast<int *>(1000002); //将整形转为指针
    cout << s << endl;

    return 0;
}