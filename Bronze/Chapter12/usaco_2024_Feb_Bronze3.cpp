#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N,Q;
    cin>>N>>Q;
    int c[N],a[N];
    for(int &i:c){cin>>i;}
    for(int &i:a){cin>>i;}
    for(int i = 0;i<N;i++){
        c[i] = c[i]-a[i];
    }

    sort(c,c+N);//O(nlog n)

    int S,V;
    while(Q--){//1.先判断Q的值，然后Q再减1
        cin>>V>>S;
        int result = N-(upper_bound(c,c+N,S)-c);//result表示S点起床能够访问到的农场数量
        if(result>=V){
            cout<<"YES"<<endl;
        }
        else{
            cout <<"NO"<<endl;
        }
    }
}
