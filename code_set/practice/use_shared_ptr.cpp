#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
    Test(){
        static int i = 0;
        cout<<"Test()"<<":"<<i++<<endl;
    }
    ~Test(){
        static int i = 0;
        cout<<"~Test()"<<":"<<i++<<endl;
    }
};

void noDefine()
{
    cout<<"no_define start running!"<<endl;
    shared_ptr<Test> p(new Test[3]);//这样是错误的用法，对于动态分配的数组，必须转递对应的释放函数

}

void slefDefine()
{
    cout<<"slefDefine start running!"<<endl;
    shared_ptr<Test> p(new Test[10],[](Test *p){delete[] p;});  //!传入lambada表达式代替delete操作。
}

int main()
{
    shared_ptr<Test> p(new Test);
    cout<<"count: "<<p.use_count()<<endl;
    int *ptr;
    cout<<"count: "<<p.use_count()<<"    size: "<<sizeof(ptr)<<"  "<<sizeof(p)<<endl;

}