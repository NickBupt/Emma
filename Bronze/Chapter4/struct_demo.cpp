#include<iostream>
using namespace std;

struct student{
    string name;
    double gpa;

    student(string n,double g):name(n),gpa(g){}
};

int main(){
    student stu1("Candy",3.7);
    student stu2("Emma",3.9);

    cout << stu2.name<<endl;
}
