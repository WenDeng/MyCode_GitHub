#include<iostream>
#include<string>
using namespace std;

//求出数组的next值
void getnext(int *next,string str)
{
    int k,len=str.length(),j=1;
    next[0]=k=-1;
    while(j<len)
    {
        if(k==-1 || str[j-1]==str[k])  next[j++]=++k;
        else k=next[k];
    }
}

//根据求出的next进行子串匹配
int string_kmp(int *next,string str,string substr)
{
    int j=0,i=0,k;
    while(j<str.length() && i<substr.length())
    {
        if(i==-1 || substr[i]==str[j]) i++,j++;//依次进行匹配
        else i=next[i];//匹配不成功，回溯
    }
    if(i==substr.length()) return j-i;
    return -1;
}

int main()
{  
    string str="abaabcac";
    int len=str.length();
    int *next=new int[len];

    getnext(next,str);
    for(int i=0;i<len;i++) cout<<next[i]<<" ";
    cout<<endl;

    cout<<"start position:"<<string_kmp(next,str,"abcb")<<endl;

    delete next;
}