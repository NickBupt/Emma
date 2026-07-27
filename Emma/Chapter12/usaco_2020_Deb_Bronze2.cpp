#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    int n;
    cin>>n;
    string A,B;
    cin>>A>>B;
    int ans = 0;//记录不相同的子串的个数
    bool mismatched = false;//前一个位置的字符是否不匹配
    for(int i = 0;i<n;i++){
        if(A[i]!=B[i]){
            if(!mismatched){
                mismatched = true;//前一个字符位置改为不匹配
                ans++;
            }
        }else{
            mismatched = false;
        }
    }

    cout << ans<<endl;
}