#include<iostream>
using namespace std;

int main(){
    int j = 1;
    while (j<=5){
        cout << j<<" ";
        j++;
    }
    cout <<endl;

    for(int i = 1;i<=5;i++){
        cout << i<<" ";
    }
    cout<<endl;

    int k = 10;
    do{
        cout << k<<" ";
    }while(k<=5);
    cout << endl;

    for(int i = 1;i<=10;i++){
        if(i==4){
            break;//直接终止循环，后续未执行的循环都不再执行
        }
        cout << i<<" ";
    }
    cout << endl;

    for(int i = 1;i<=10;i++){
        if(i%3==0){
            continue;//跳过当前循环中未执行的语句，直接进入下一次循环
        }
        cout << i<<" ";
    }
    cout << endl;
}
