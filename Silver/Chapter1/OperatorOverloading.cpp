#include<iostream>
using namespace std;

typedef pair<int, int> pi;//对儿
typedef long long ll;

const int MOD = 1000000007;

int add(int a, int b, int mod = MOD)
{
    return ((long long)a + b) % mod;
}

pi operator+(const pi& l, const pi& r)
{
    return {add(l.first, r.first), add(l.second, r.second)};
}

pi operator - (const pi& l, const pi& r){
    return {l.first*2,r.first*2};
}

pi operator*(const pi& l,int b){
    return {l.first/b,l.second/b};
}

int main()
{
    pi pair1 = {1000000008, 1000000009};
    pi pair2 = {2, 1000000008};
    pi addedPair = pair1 + pair2;
    cout << addedPair.first << " " << addedPair.second << endl;

    pi pair3 = {6,10};
    pi result = pair3*2;
    cout << result.first<<" "<<result.second<<endl;

    int num1 = 5;
    int num2 = 10;
    pi pair4 = {1,3};
    cout << num1*num2<<endl;
    cout << num1+num2<<endl;
}
