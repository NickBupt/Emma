#include<iostream>
#include <vector>
using  namespace std;

int main(){
    vector<int> v = {1,3,5,7,9};
    if(find(v.begin(),v.end(),4)!=v.end()){
        cout << "4 is in v."<<endl;
    }
    else{
        cout << "4 is not in v."<<endl;
    }
}
