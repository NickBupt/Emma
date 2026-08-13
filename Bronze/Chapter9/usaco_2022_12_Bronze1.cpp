#define ll long long
#include<iostream>
#include<algorithm>
using namespace std;
//using ll = long long;
//typedef long long  ll;

int main(){
    ll N;
    cin >> N;
    ll c[N];
    for(ll &j:c){
        cin>> j;
    }

    sort(c,c+N);
    ll max = 0;
    ll num = 0;
    for(ll i = 0;i<N;i++){
        ll total = c[i]*(N-i);
        if(total>max){
            max = total;
            num = c[i];
        }
    }
    cout << max<<" "<< num<<endl;

}
