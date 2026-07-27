#include<iostream>
using namespace std;

int main(){
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    int before[4],after[4];
    for(int i = 0;i<4;i++){
        cin>>before[i]>>after[i];
    }

    int total1 = 0,total2 = 0;
    for(int i = 0;i<4;i++){
        total1+=before[i];
        total2+=after[i];
    }

    int extra = total2-total1;
    before[0]+=extra;

    int BronzeToSilver = before[0]-after[0];
    int SilverToGold = BronzeToSilver+before[1] - after[1];
    int GoldToPlatinum = SilverToGold+before[2] - after[2];

    cout << BronzeToSilver<<endl<<SilverToGold<<endl<<GoldToPlatinum<<endl;
}
