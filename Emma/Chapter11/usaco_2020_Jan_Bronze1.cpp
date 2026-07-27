#include<iostream>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;

    string words[N];
    for(int i= 0;i<N;i++){
        cin>>words[i];
    }

    int word_len = 0;
    for (int i = 0; i < N; i++) {
        word_len += words[i].length();

        if (word_len <=K) {
            if(i!=0){
                cout << " ";
            }
            cout << words[i];
        }
        else{
            cout<<"\n"<<words[i];
            word_len = words[i].length();
        }
    }
}
