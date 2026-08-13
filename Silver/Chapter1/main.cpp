#include<iostream>
using namespace std;

int main() {
    //时间的对比情况
    clock_t startTime,endTime;
    startTime = clock();
    ios::sync_with_stdio(false);//解除scanf和printf的绑定
    cin.tie(0);//免除缓冲区的刷新
    for(int i =0;i<10000;i++){
        cout << "Hello, World!" << endl;
    }
    endTime = clock();
    cout << "Running time is: "<< (double)(endTime - startTime) << "ms" << endl;
}
