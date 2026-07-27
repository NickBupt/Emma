#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>v){
    for(int i = 0;i<v.size();i++){
        cout << v[i]<<" ";
    }
    cout << endl;
}

int main(){
    vector<int> v;//创建一个动态整数数组v，里面没有元素
    vector<int> v1(5);//创建一个初始状态含有5个整数的动态数组，所有元素均为随机数
    vector<int> v2(5,6);//创建一个初始状态含有5个6的动态数组
    vector<int> v3 = {1,3,4,6,8};

    if(v.empty()){
        cout << "v is empty now."<<endl;
    }

    cout << "v1 has "<< v1.size()<<" elements."<<endl;

    //initialize
    for(int i = 1;i<=5;i++){
        v.push_back(i);
    }
    printVector(v);

    for(int i = 0;i<v1.size();i++){
        v1[i] = i+1;
    }
    printVector(v1);

    cout <<"the first element in v is " <<*v.begin()<<endl;
    cout <<"the last element in v is "<<*(v.end()-1)<<endl;

    v.pop_back();//删除最后一个元素
    printVector(v);//1 2 3 4

    v.insert(v.begin()+3,9);
    printVector(v);
    v.insert(v.begin()+3,3,10);//1 2 3 10 10 10 9 4
    printVector(v);

    v.erase(v.begin()+3);//1 2 3 10 10 9 4
    printVector(v);

    v.erase(v.begin()+3,v.begin()+5);//1 2 3 9 4
    printVector(v);

    vector<vector<int>> v4;
    v4.push_back({1,2,3});
    v4.push_back({4,5});
    v4.push_back({6,7,8,9});

    for(int r = 0;r<v4.size();r++){//r:row index
        for(int c = 0;c<v4[r].size();c++){
            cout << v4[r][c]<<" ";
        }
        cout << endl;
    }

    //迭代器
    for(auto it = v.begin();it!=v.end();it++){
        cout << *it<<" ";
    }
    cout << endl;
}
