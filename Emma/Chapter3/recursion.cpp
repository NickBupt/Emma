#include<iostream>
using namespace std;

int factorial(int n ){
    if(n==1){//base case ：基本情况，用来终止递归
        return 1;
    }
    return n* factorial(n-1);
}

int fibonacci(int n){
    if(n==1||n==2){
        return 1;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
}

int main(){
    cout << factorial(5)<<endl;
}
