#include<iostream>
using namespace std;

int main(){
    int num = 10;
    int *p = &num;//p 指针变量
    cout << p<<endl;
    cout << *p<<endl;//*:解地址符

    string food = "Pizza";
    cout << food<<endl;
    cout << &food<<endl;//&:取地址符

    string &str1 = food;//给food变量起别名叫上str1
    food = "burger";
    cout << str1<<endl;
}
