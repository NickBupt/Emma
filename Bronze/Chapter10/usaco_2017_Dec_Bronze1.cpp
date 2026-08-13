#include<iostream>
using namespace std;

struct Rectangle{
    int x1,y1,x2,y2;
};

int area(int x1,int y1,int x2,int y2){
    return (x2-x1)*(y2-y1);
}

int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);

    Rectangle r1,r2, truck;
    cin>>r1.x1>>r1.y1>>r1.x2>>r1.y2;
    cin>>r2.x1>>r2.y1>>r2.x2>>r2.y2;
    cin>>truck.x1>>truck.y1>>truck.x2>>truck.y2;

    int total = area(r1.x1,r1.y1,r1.x2,r1.y2)+ area(r2.x1,r2.y1,r2.x2,r2.y2);
    int block1 = max(0,min(r1.x2,truck.x2)-max(r1.x1,truck.x1))*
                 max(0,min(r1.y2,truck.y2)-max(r1.y1,truck.y1));

    int block2 = max(0,min(r2.x2,truck.x2)-max(r2.x1,truck.x1))*
                 max(0,min(r2.y2,truck.y2)-max(r2.y1,truck.y1));

    int visiable = total - block1 - block2;
    cout << visiable<<endl;
}
