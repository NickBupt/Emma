#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int len1 = b-a;
    int len2 = d-c;

    int overlap;
    if(min(b,d)-max(a,c)>0){
        overlap = min(b,d)-max(a,c);
    }
    else{
        overlap = 0;
    }

    cout << len1+len2-overlap<<endl;

}