#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

int main(){
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(4);
    us.insert(1);

    for(int i:us){
        cout << i<<" ";
    }
    cout <<endl;

    cout << us.count(1)<<endl;//统计一下1出现的次数
    us.erase(1);

    for(int i:us){
        cout << i<<" ";
    }
    cout <<endl;

    set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(2);
    for(int i:s){
        cout <<i<<" ";
    }
    cout <<endl;

    if(s.find(3)==s.end()){
        cout << "3 is not in s"<<endl;
    }
    else{
        cout << "3 is in s"<<endl;
    }


}
