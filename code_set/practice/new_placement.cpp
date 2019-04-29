#include <iostream>
#include <new>
#include <memory>
using namespace std;

class Test
{
public:
    Test(int q)
    {
        k = q;
    }
    void show()
    {
        cout << k << endl;
    }
    int k;
};

int main()
{
    Test *p = (Test *)malloc(sizeof(Test));
    new (p) Test(9);//new placement运算子
    cout << "p value:";
    p->show();
    cout << endl;

    return 0;
}