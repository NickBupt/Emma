#include<iostream>
using namespace std;

int main()
{
    string cows[] = {"Bessie","Buttercup","Belinda","Beatrice",
                     "Bella","Blue","Betsy","Sue" };

    sort(cows,cows+8);
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int N;
    cin>>N;
    vector<pair<string,string>> edges;//必须存在的边
    string cow1,cow2;
    for(int i = 0;i<N;i++){
        cin>>cow1>>cow2>>cow2>>cow2>>cow2>>cow2;
        edges.push_back({cow1,cow2});
        edges.push_back({cow2,cow1});
    }

    do{
        vector<pair<string,string>> edges1;//所有边
        for(int i = 0;i<7;i++){
            edges1.push_back({cows[i],cows[i+1]});
            edges1.push_back({cows[i+1],cows[i]});
        }
        int count = 0;//必须存在的边的条数
        for(int i = 0;i<2*N;i++){
            if(find(edges1.begin(), edges1.end(),edges[i])!=edges1.end()){
                count++;
            }
        }
        if(count==2*N){
            break;
        }
    }while(next_permutation(cows,cows+8));
    for(string cow:cows){
        cout<<cow<<endl;
    }
}
