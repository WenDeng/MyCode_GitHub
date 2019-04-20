#include<iostream>
using namespace std;
class Singleton
{
  private:
  	static Singleton instance; // 单例对象在这里！
  	
  private:
	Singleton(){ cout << "单例对象创建！" << endl; };
	Singleton(const Singleton &);
	Singleton& operator=(const Singleton &);
	~Singleton(){ cout << "单例对象销毁！" << endl; };
 
  public:
	static Singleton* getInstance()
	{		
		return &instance;//第一次调用时才会调用构建函数
	}
};

Singleton Singleton::instance;//直接生成一个全局性的对象
int main()
{
	Singleton *ct1 = Singleton::getInstance();
	Singleton *ct2 = Singleton::getInstance();
	Singleton *ct3 = Singleton::getInstance();
 
	return 0;
}