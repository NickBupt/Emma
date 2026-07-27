#include<iostream>
using namespace std;


int main(){
//    freopen("word.in","r",stdin);
//    freopen("word.out","w",stdout);

    int N, K;
    cin >> N >> K;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    //int word_len = 0;
    int word_len = 0;
    vector<string> line;
    string word = "";
    for (int i = 0; i < N; i++) {
        word_len+=words[i].length();
        if (word_len <=K) {
            if(i!=0){
                word = " "+words[i];
            }
            else{
                word += word[i];
            }
        }
        else{
            line.push_back(word);
            word = "";
            word_len = 0;
        }
    }

    for(string s:line){
        cout << s<<endl;
    }

    return 0;
}
