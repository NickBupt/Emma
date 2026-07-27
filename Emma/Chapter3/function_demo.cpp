#include<iostream>
using namespace std;

int getSum(int x,int y){//x,y are parameters , and return type is int
    int sum = x+y;
    return sum;
}

double cube(double x);

void greeting(string name){
    cout << "Hello, "<<name<<endl;
}

void increase(int &x){//C++ reference
    x++;
}

int main(){
    int result = getSum(3,4);//直接将getSum当作是与之对应的return type的值使用
    cout << result << endl;

    cout << cube(2)<<endl;
    greeting("Emma");

    int num = 10;
    increase(num);
    cout << num<<endl;
}

double cube(double x){
    return x*x*x;
}