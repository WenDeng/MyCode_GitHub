#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class A
{
   public:
   A(int a){ a=a;};
   virtual void showA(){ cout<<"a:"<<a<<endl;};
   void printvalue()
   {
      cout<<"hello world!"<<endl;
      showA();
   }
   int a;
};


class B:public A
{
   public:
   B(int a,int b):A(a),b(b){};
   virtual void showA(){ cout<<"b:"<<b<<endl;}
   int b;
};

bool compare(int a,int b)
{
   return a>b?true:false;
}

bool isElemet(int value)
{
   return value<5;
}


int main()
{
   B b(2,3);
   b.showA();
   b.printvalue();

   int value[10]={1,2,3,4,5,5,4,4,5,6};
   value[2]=-value[2];  //测试直接取反，我突然发现c++是真他妈强大
   vector<int> data(value,value+10);
   sort(value,value+10,compare);//测试数组排序
   sort(data.begin(),data.end(),compare);//测试vector排序
   // for(auto &foo : value) cout<<foo<<" "; //测试for循环，这个语句就很骚
   // cout<<endl;

   for(auto &ver:data) cout<<ver<<" ";//vector<int>::iterator iter;
   
   cout<<"\nThe first value(satisfied): ";
   cout<<*find_if(data.begin(),data.end(),isElemet)<<endl; //测试find_if算法，记住for_each,make_plural等算法;
   return 0;

}
