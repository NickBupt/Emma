#include <iostream>
typedef long long ll;

using namespace std;

int main() {
    ll N,M;
    cin>>N>>M;
    ll height[N];
    for(int i = 0;i<N;i++){
        cin >>height[i];
    }

    for(int i = 0;i<M;i++){
        int length;
        cin >> length;

        int l = 0;//l表示糖的最低点

        for(int j = 0;j<N&&l<length;j++){
            int diff = max(0,(int)min(height[j],(ll)length)-l);
            height[j] += diff;
            l+=diff;
        }
    }

    for(int i = 0;i<N;i++){
        cout << height[i]<<endl;
    }
}


