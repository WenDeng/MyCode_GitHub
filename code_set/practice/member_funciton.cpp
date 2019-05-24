#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
class A 
{
public:
    static void staticmember(){cout<<"static"<<endl;}   //static member
    void nonstatic(){cout<<"nonstatic"<<endl;}          //nonstatic member
    virtual void virtualmember(){cout<<"virtual"<<endl;};//virtual member
};
int main()
{
    A a;
    //static成员函数,取得的是该函数在内存中的实际地址，而且因为static成员是全局的，所以不能用A::限定符
    void (*ptrstatic)() = &A::staticmember;      

    //nonstatic成员函数 取得的是该函数在内存中的实际地址     
    void (A::*ptrnonstatic)() = &A::nonstatic;

    //虚函数取得的是虚函数表中的偏移值，这样可以保证能过指针调用时同样的多态效果
    void (A::*ptrvirtual)() = &A::virtualmember;
    
    //函数指针的使用方式
    ptrstatic();
    (a.*ptrnonstatic)();
    (a.*ptrvirtual)();
}
