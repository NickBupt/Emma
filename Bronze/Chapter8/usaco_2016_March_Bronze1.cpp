#include<iostream>
using namespace std;

int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int N,K;
    cin>>N>>K;
    int d[N];

    for(int &i:d){
        cin>>i;
    }

    sort(d,d+N);

    int max = 0;
    for(int i = 0;i<N;i++){//假设第i的钻石是当前柜台的最小钻石
        int count = 1;
        for(int j = i+1;j<N;j++){
            if(d[j]-d[i]<=K){
                count++;
            }

        }
        if(count>max){
            max =count;
        }
    }
    cout << max;
}
