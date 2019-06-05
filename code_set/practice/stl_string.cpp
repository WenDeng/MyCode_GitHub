#include<string>
#include<cstring>
#include<iostream>

using namespace std;

//C++中string、char *、char[]的转换
int main()
{
    //----------------C++中string、char *、char[]的转换-------------------------------------------
    string str = "hello";//string to char*
    const char *p = str.data(); //加const  或者用char * p=(char*)str.data();的形式
    const char *q = str.c_str(); //同上，要加const或者等号右边用char*

    string str = "hmmm"; //string to char*
    char cstr[50];
    str.copy(cstr, 5, 0); //这里5代表复制几个字符，0代表复制的位置，
    *(cstr + 5) ='\0';   //注意手动加结束符！！！

    string s;
    char *cs = "hello"; //直接赋值
    s = cs; //直接将char转为string
    //--------------------------------------------------------------------------------------------
    
    //------------------------------------整数和字符串之间的转换-----------------------------------
    string myInfo;
    int age=18,number=201322060935;
    myInfo+="name: dengwen   ";
    myInfo+="age: "+to_string(age)+"   ";
    myInfo+="number: "+to_string(number);
    cout<<myInfo<<endl;

    int k=atoi("18");
    cout<<k<<endl;
}