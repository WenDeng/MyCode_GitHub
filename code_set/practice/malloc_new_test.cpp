#include <iostream>
#include <cstdlib>
using namespace std;
class Foo
{
    public:
        int a;
        int b;
        Foo(){ cout<<"constructor!"<<endl;};
        ~Foo(){ cout<<"destructor!"<<endl;};
        void* operator new(size_t n)
        {
            void *p=malloc(sizeof(Foo));
            return p;
        }
};

int main()
{
    Foo a;
    Foo *b=new Foo;
    Foo *c=(Foo *)operator new(sizeof(Foo));

    int *ver_a=new int;
    int *ver_b=(int *)malloc(sizeof(int));
    cout<<a.a<<" "<<b->a<<" "<<c->a<<endl;
    cout<<*ver_a<<" "<<*ver_b<<endl;
    delete c;
    delete b;
    return 0;
}
