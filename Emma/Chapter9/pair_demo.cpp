#include<iostream>
using namespace std;

int main() {
    vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back(make_pair(2, 3));
    v.push_back({1,3});

    for(auto it = v.begin();it!=v.end();it++){
        cout << it->first<<" "<< (*it).second<<endl;
    }
}