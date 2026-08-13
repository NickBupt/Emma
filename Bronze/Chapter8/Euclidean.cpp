#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    int x[N],y[N];

    for(int &i:x){
        cin>>i;
    }

    for(int &j:y){
        cin>>j;
    }

    int lengthSquare = 0;
    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            int distance = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if(distance>lengthSquare){
                lengthSquare = distance;
            }
        }
    }

    cout << lengthSquare<<endl;
}
