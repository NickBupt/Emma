#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> limit(100);
    vector<int> speed(100);

    int pos = 0;

    // 读入道路限速，并展开成 100 格
    for (int i = 0; i < N; i++) {
        int length, speedLimit;
        cin >> length >> speedLimit;

        for (int j = 0; j < length; j++) {
            limit[pos] = speedLimit;
            pos++;
        }
    }

    pos = 0;

    // 读入 Bessie 的速度，并展开成 100 格
    for (int i = 0; i < M; i++) {
        int length, bessieSpeed;
        cin >> length >> bessieSpeed;

        for (int j = 0; j < length; j++) {
            speed[pos] = bessieSpeed;
            pos++;
        }
    }

    int difference = 0;

    for (int i = 0; i < 100; i++) {
        difference = max(difference, speed[i] - limit[i]);
    }

    cout << difference << endl;

    return 0;
}
/*
算法步骤：

1. 读入 N 和 M。

2. 建立两个长度为 100 的数组：
   limit[i] 表示第 i mile 的限速。
   speed[i] 表示第 i mile Bessie 的速度。

3. 读入 N 段道路限速。
   对每一段 length, v，把接下来 length 个位置填成 v。

4. 读入 M 段 Bessie 的速度。
   对每一段 length, v，把接下来 length 个位置填成 v。

5. 枚举 i = 0 到 99：
   ans = max(ans, speed[i] - limit[i])

6. 如果没有超速，ans 保持为 0。

7. 输出 ans。
*/