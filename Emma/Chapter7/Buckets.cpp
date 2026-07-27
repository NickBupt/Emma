#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int C[N],A[N];
    for(int &j:C){
        cin>>j;
    }

    for(int &j:A){
        cin>>j;
    }

    for(int i = 0;i<N-1;i++){
        int pour = min(A[i],C[i+1]-A[i+1]);
        A[i] -= pour;
        A[i+1] +=pour;
    }

    for(int i:A){
        cout <<i<<" ";
    }
}
