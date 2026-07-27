#include<iostream>
using namespace std;

int main(){
    freopen("cowsignal.in","r",stdin);//r:read
    freopen("cowsignal.out","w",stdout);//w:write
    int M,N,K;
    cin>>M>>N>>K;
    char signal[M][N];

    for(int r = 0;r<M;r++){
        for(int c = 0;c<N;c++){
            cin>>signal[r][c];
        }
    }

    char result[K*M][K*N];
    for(int r = 0;r<M;r++){
        for(int c = 0;c<N;c++){
            result[K*r][K*c]=signal[r][c];
            for(int i = K*r;i<K*r+K;i++){
                for(int j = K*c;j<K*c+K;j++){
                    result[i][j] = signal[r][c];
                }
            }
        }
    }

    for(int i = 0;i<K*M;i++){
        for(int j = 0;j<K*N;j++){
            cout<<result[i][j];
        }
        cout <<endl;
    }
}

