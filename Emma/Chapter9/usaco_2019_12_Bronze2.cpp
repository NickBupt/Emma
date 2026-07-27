#include <iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//该两行是加速代码运行的

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    string s;

    cin >> N;
    cin >> s;

    for (int K = 1; K <= N; K++) {
        set<string> seen;
        bool ok = true;

        for (int i = 0; i + K <= N; i++) {
            string sub = s.substr(i, K);

            if (seen.count(sub)) {
                ok = false;
                break;
            }

            seen.insert(sub);
        }

        if (ok) {
            cout << K << '\n';
            return 0;
        }
    }

    return 0;
}
