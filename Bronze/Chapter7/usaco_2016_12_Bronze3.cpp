#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    freopen("cowsignal.in","r",stdin);//r:read 进行输入
    freopen("cowsignal.out","w",stdout);//w:write 进行输出
    int M,N,K;
    cin>>M>>N>>K;

    string str[M];
    for(int i = 0;i<M;i++){
        cin>>str[i];
    }

    for(int i = 0;i<M;i++){//遍历string数组中的每一个元素
        for(int l = 0;l<K;l++){
            for(int j = 0;j<N;j++){//打印每一个character
                for(int k = 0; k<K;k++){
                    cout<<str[i][j];
                }
            }
            cout << endl;
        }
    }
}
