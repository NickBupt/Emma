#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> x(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    // 特殊情况：只有一头牛，必须给它一个球
    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    vector<int> target(N);
    vector<int> indegree(N, 0);

    // 计算每头牛会传给谁
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            target[i] = 1;
        } else if (i == N - 1) {
            target[i] = N - 2;
        } else {
            int leftDist = x[i] - x[i - 1];
            int rightDist = x[i + 1] - x[i];

            if (leftDist <= rightDist) {
                target[i] = i - 1;   // 距离相等时传给左边
            } else {
                target[i] = i + 1;
            }
        }

        indegree[target[i]]++;
    }

    int answer = 0;

    // 入度为 0 的牛必须一开始发球
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            answer++;
        }
    }

    // 特殊处理孤立二元环
    for (int i = 0; i < N; i++) {
        int j = target[i];

        // i < j 避免同一个二元环重复计算
        if (i < j && target[j] == i) {
            if (indegree[i] == 1 && indegree[j] == 1) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
/*
算法步骤：

1. 读入 N 和所有牛的位置。

2. 将位置从小到大排序。

3. 对每头牛 i，找到它会传给谁 target[i]：
   - 最左边牛只能传给右边牛；
   - 最右边牛只能传给左边牛；
   - 中间牛比较左右距离，距离相等时传给左边。

4. 统计每头牛的入度 indegree[target[i]]++。

5. 每个 indegree[i] == 0 的牛都必须初始发球，答案加 1。

6. 再检查互相传球的二元环：
   如果 target[i] = j 且 target[j] = i，
   并且 indegree[i] == 1、indegree[j] == 1，
   说明这个二元环没有外部球传入，答案加 1。

7. 输出答案。
*/