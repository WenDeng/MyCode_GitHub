#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char b[5];
    char a[30];
    snprintf(b,5,"%%%ds",5);
    scanf(b,a);
    printf("%s",a);
    return 0;
}