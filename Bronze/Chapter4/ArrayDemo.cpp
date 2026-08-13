#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,3,5,7,9};//数组

    for(int k:arr){
        cout << k<<" ";
    }
    cout << endl;

    for(int i = 0 ;i<5;i++){
        cout << arr[i]<<" ";
    }
    cout <<endl;

    int arr2[2][3] = {{1,2,3},
                      {4,5,6}};

    //row-major order traversing
    for(int r = 0;r<2;r++){
        for(int c = 0;c<3;c++){
            cout << arr2[r][c]<<" ";
        }
    }
    cout << endl;

    //column-major order traversing
    for(int c = 0;c<3;c++){
        for(int r = 0;r<2;r++){
            cout << arr2[r][c]<<" ";
        }
    }
    cout << endl;

}
