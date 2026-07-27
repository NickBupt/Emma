#include<iostream>
using namespace std;

int main(){
    int score;
    cout << "Please enter your score: ";
    cin>> score;
    if(score>=90){
        cout << "Watch TV for 2 hours"<<endl;
    }
    else if(score>=80){
        cout << "Watch TV for 1.5 hours"<<endl;
    }
    else if(score>=70){
        cout << "Watch TV for 1 hour"<<endl;
    }
    else{
        cout << "Wash dishes";
    }

    return 0;
}
