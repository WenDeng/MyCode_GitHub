#include <deque>
#include <iostream>
#include <algorithm>
#include<vector>
#include <memory>
using namespace std;
//如果程序员没有显式实现一个拷贝构造函数，那么编译器会根据需要决定是否自己构造一个，如果满足那四个
//条件，那么会构造出一个non-trival的拷贝构造函数，然后调用对应的拷贝构造函数，这时如果派生类有指针，拷贝构造函数其实也是浅拷贝的。

//如果没有显式实现拷贝构造函数，也不满足那四个条件，那么会编译器不会合成default copy constructor
//而直接进行浅拷贝，也就是多个指针可能指向同一块内存。这可能会导致的问题就是一个对象被delete，会影响另一个对象的值

class Base
{
public:
    Base(int t=0) {k=t;}
    Base(Base &temp)
    {
        cout<<"this is Base copy construct!!"<<endl;
        k=temp.k;
    }
    void operator =(Base &temp)
    {
        cout<<"this is Base copy assignment operator!!"<<endl;
        k=temp.k;
    }
public:
    int k;
};

class Test
{
public:
    // Test(int k,int j):b(j)
    Test(int k,int j)
    {
        cout<<"Deprived constructor!!!"<<endl;
        p=new int;
        *p=k;
    }
    Test(Test &temp)
    {
        cout<<"this is Depreived copy construct!!"<<endl;
        // b=(temp.b);
        p=new int;
        *p=*temp.p;
    }
    void showAdrress() //输出成员变量*p的值和地址
    {
        cout<<*p<<"  "<<p<<endl;
    }
    ~Test()
    {
        cout<<"Test desconstructor"<<endl;
        delete p;//讲道理，浅拷贝重复两次释放应该会出错的吧！
        p=NULL;
    }
private:
    int *p;
    // Base b;
};

int main()
{
    Test test(5,3);
    test.showAdrress();

    cout<<endl;
    Test test1=test;
    test.~Test();//析构
    test1.showAdrress();

    Test *q=new Test(3,5);//测试能否对一个对象delete两次，测试结果表面delete只会改变指针所指地址的值，而不会改变其所指的地址
    cout<<endl<<q<<"  ";
    q->showAdrress();
    delete q;//第一次delete
    cout<<q<<"  ";
    q->showAdrress();
    delete q;//第二次delete
    cout<<q<<"  ";
    q->showAdrress();

    cout<<endl;
    int *tempa=NULL,*tempb=NULL;
    tempa=(int*)malloc(sizeof(int)); //测试能否对一个指针free两次
    tempb=tempa;
    free(tempa);
    free(tempb);

    return 0;
}