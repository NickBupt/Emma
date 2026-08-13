#include <iostream>
#include<vector>
using namespace std;

struct Mountain {
    long long x,y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    int N; cin>>N;
    vector<Mountain> mountains(N);
    for (int i=0;i<N;i++){
        cin>>mountains[i].x>>mountains[i].y;
    }

    // 排序
    sort(mountains.begin(), mountains.end(), [](const Mountain &a, const Mountain &b){
        long long A = a.x - a.y;
        long long B = b.x - b.y;
        if(A!=B) return A<B;
        else {
            // 当x-y相同，以x+y降序排序
            long long A2 = a.x + a.y;
            long long B2 = b.x + b.y;
            return A2>B2;
        }
    });

    int countVisible =0;
    long long maxR = -1; // 用于记录已处理过的山中的最大 x+y
    for (auto &m : mountains){
        long long R = m.x + m.y;
        if(R>maxR){
            countVisible++;
            maxR=R;
        }
    }

    cout<<countVisible<<"\n";

    return 0;
}
