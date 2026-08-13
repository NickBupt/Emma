#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[5] = {3,1,2,5,4};
    sort(arr,arr+5);
    cout << lower_bound(arr,arr+5,2)<<endl;//第一个大于等于2的元素的位置
    cout << *lower_bound(arr,arr+5,2)<<endl;

    cout << upper_bound(arr,arr+5,2)<<endl;//第一个大于2的元素的位置
    cout << *upper_bound(arr,arr+5,2)<<endl;

    vector<int> v = {1,2,3,4,5};
    cout << *lower_bound(v.begin(),v.end(),2)<<endl;
}
/*
 * upper lower bound使用的是二分搜索，时间复杂度为O(logn)
 */
