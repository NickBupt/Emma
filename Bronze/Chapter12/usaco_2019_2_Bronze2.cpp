#include <iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> color(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int c = 1; c <= 4; c++) {
            bool ok = true;

            for (int neighbor : graph[i]) {
                if (color[neighbor] == c) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                color[i] = c;
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << color[i];
    }

    cout << '\n';

    return 0;
}
/*
算法步骤：

1. 把每块草地看成图上的点。

2. 如果一头牛喜欢草地 a 和 b，
   就在 a 和 b 之间连边，表示它们颜色不能相同。

3. 从草地 1 到 N 依次染色。

4. 对当前草地 i，依次尝试颜色 1,2,3,4。

5. 如果某个颜色没有和已经染色的相邻草地冲突，
   就选择这个颜色。

6. 因为每个草地最多相邻 3 个点，
   而颜色有 4 种，所以一定能选到颜色。

7. 按顺序选择最小可用颜色，
   得到的就是字典序最小答案。
*/