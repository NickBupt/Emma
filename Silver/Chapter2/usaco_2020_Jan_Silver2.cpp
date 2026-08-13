#include <iostream>
using namespace std;

bool valid(long long n, long long k, long long m, long long x) {
    long long g = 0;
    while (k > 0 && g < n) {
        long long y = (n - g) / x;
        if (y < m) {
            long long leftover = (n - g + m - 1) / m;
            return leftover <= k;
        }
        long long maxmatch = n - x * y;
        long long numdays = (maxmatch - g) / y + 1;
        if (numdays > k) numdays = k;
        g += y * numdays;
        k -= numdays;
    }
    return g >= n;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    long long n, k, m;
    cin >> n >> k >> m;
    long long lhs = 1;
    long long rhs = 1e12;
    while (lhs < rhs) {
        long long mid = (lhs + rhs + 1) / 2;
        if (valid(n, k, m, mid)) {
            lhs = mid;
        } else {
            rhs = mid - 1;
        }
    }
    cout << lhs << endl;
    return 0;
}
/*
算法步骤：

1. 读入 N, K, M，保证 K*M < N。
2. 二分查找最大的 X，范围 [1, 1e12]（实际上界 N 足够）。
3. 判定函数 valid(n, k, m, x)：
   a. 用 g 记录已还牛奶，k 为剩余天数。
   b. 循环当 k>0 且 g<n 时：
      - 计算理论当天还款 y = (n - g) / x。
      - 若 y < m，则之后每天只能还 m，直接判断剩余天数是否够用（上取整）。
      - 若 y >= m，则利用公式计算当前 y 能持续多少天（批量跳过）：
         * 设 r = (n - g) % x，则可持续天数 = r / y + 1。
         * 用 maxmatch = n - x*y 来得到 g + r，从而计算天数。
         * 批量更新 g 和 k。
   c. 循环结束，返回 g >= n。
4. 二分查找，若 mid 可行则向左（增大X）移动，否则向右（减小X）移动。
5. 输出最大可行 X。
*/
