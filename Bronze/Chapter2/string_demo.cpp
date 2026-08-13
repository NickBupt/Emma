#include<iostream>
using namespace std;

int main(){
    string fName = "Harry";
    string lName = "Morgan";
    string fullName = fName+" "+lName;
    cout << fullName<<endl;
    cout << fName.append(lName)<<endl;

    string str = "Hello, World!";
    cout << str.length()<<endl;
    cout << str.size()<<endl;

    cout << "winter is \ncoming"<<endl;// \n-->new line
    cout << "winter is \"coming"<<endl;// \"--"
    cout << "winter is \\coming"<<endl;// \\--\

    //input
//    int age;
//    cout << "Please enter your age:";
//    cin>>age;
//    cout << "You are "<< age << " years old."<<endl;

//    string fullName1;
//    getline(cin,fullName1);
//    cout << fullName1<<endl;

    string str1 = "abcdefghijk";
    cout << str1.substr(0,3)<<endl;//从0号开始，总共找出三个字符
    cout << str1.substr(4,2)<<endl;
}
