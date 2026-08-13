#include<iostream>
using namespace std;

void printVector(vector<int> v){
    for(int i:v){
        cout<< i<<" ";
    }
    cout << endl;
}

int main(){
    vector<int> v;
    for(int i  = 0;i<3;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    do{
        printVector(v);
    }while(next_permutation(v.begin(),v.end()));//1.生成下一个排序
    // 2判断是否还有下一个排序，没有的话返回false

    char c[3];
    for(char &c1:c){
        cin>>c1;
    }
    for(char c1:c){
        cout << c1;
    }
    cout << endl;

    sort(c,c+3);
    do{
        for(char c1:c){
            cout << c1;
        }
        cout << endl;
    }while(next_permutation(c,c+3));
}
