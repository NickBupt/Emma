#include<iostream>//插入进行输入输出的文件
using namespace std;
/*
 * 这是一个多行注释
 */

int main(){//main function:程序的主入口，程序开始执行的位置
    cout << "Hello, World!"<<endl;//endl 自动换行

    int age = 16;
    double weight = 22.35;
    char c = 'a';
    string str = "Hello, World!";
    bool flag = true;

    long long num = 99999999999999999;

    cout << "I am "<<age << " years old."<<endl;

    //operator
    int num1 = 10;
    num1++;//num1+=1  num1 = num1+1
    cout << num1<<endl;

    num1--;//num1-=1
    cout << num1<<endl;

    //logic operator
    cout << ((1<5)&&(2<1))<<endl;//and
    cout << ((1<5)||(2<1))<<endl;// or
    cout << !(2<5)<<endl;// not
}
