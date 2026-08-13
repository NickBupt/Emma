#include <iostream>
using namespace std;

int N,a,b;
int d[100000];

int main()
{
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    cin >> N;
    for(int i=1;i<N;i++)
    {
        cin >> a >> b;
        d[a-1]++, d[b-1]++;
    }
    int D = d[0];
    for(int i=1;i<N;i++)
        if(d[i] > D)
            D = d[i];
    cout << D+1 << '\n';
}

/*
算法步骤：

1. 读入 N。

2. 树有 N 个点和 N-1 条边。

3. 对每条边 a-b：
   degree[a]++
   degree[b]++

4. 找到所有点中的最大度数 maxDegree。

5. 如果某个点有 maxDegree 个邻居，
   那么这个点和它的所有邻居必须两两草种不同，
   所以至少需要 maxDegree + 1 种草。

6. 对树来说，maxDegree + 1 种草一定够用。

7. 输出 maxDegree + 1。
*/