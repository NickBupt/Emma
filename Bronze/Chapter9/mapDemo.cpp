#include<map>
#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    map<int,string> students;
    students[1] = "Candy";
    students.insert({2,"Bob"});
    students.insert(make_pair(3,"Cathy"));

    for(auto it = students.begin();it!=students.end();it++){
        cout << it->first<<" "<<(*it).second<<endl;
    }

    students.erase(2);
    for(auto it = students.begin();it!=students.end();it++){
        cout << it->first<<" "<<it->second<<endl;
    }
}