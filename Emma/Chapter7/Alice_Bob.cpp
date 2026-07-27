#include<iostream>
using namespace std;

int main(){
    int R,S,M,N,P,Q;
    cin>>R>>S>>M>>N>>P>>Q;

    int Ax = 0,Ay = 0;
    int Bx = R,By = S;

    int time = 0;
    while(Ax<Bx&&Ay<By){
        Ax+=M;
        Ay+=N;
        Bx-=P;
        By-=Q;
        time++;
    }

    if(Ax==Bx&&Ay==By){
        cout << time<<endl;
    }
    else{
        cout << -1<<endl;
    }
}
