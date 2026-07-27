#include<iostream>
using namespace std;

int main(){
    int arr[5] = {3,2,5,7,9};
    sort(arr,arr+5);
    for(int i:arr){
        cout << i<<" ";
    }
    cout << endl;

    vector<int> v = {3,2,5,7,9};
    sort(v.begin(),v.end());
    for(int i:v){
        cout << i<<" ";
    }
}

