#include <iostream>
#include <algorithm>
using namespace std;

int N,M,C;
int t[100000];

//判定函数：在最大等待时间为wait下，大巴M辆够不够用
bool pos(int wait)
{
    int wagons = 1;//大巴数量
    int firstArrival = t[0];
    int firstIndex = 0;
    for(int i=1;i<N;i++)
    {
        if(t[i] - firstArrival > wait || i + 1 - firstIndex > C)
        {
            wagons += 1;//启用下一个大巴
            firstArrival = t[i];//新大巴中第一只到达的奶牛的到达时间
            firstIndex = i;//新大巴中第一头达到奶牛的编号
        }
    }
    return (wagons <= M);
}

int binSearch(int low,int high)
{
    if(low == high) return low;
    if(low + 1 == high)
    {
        if(pos(low)) return low;
        return high;
    }
    int mid = (low+high)/2;
    if(pos(mid)) return binSearch(low,mid);
    else return binSearch(mid+1,high);
}

int main()
{
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin >> N >> M >> C;
    for(int i=0;i<N;i++)
        cin >> t[i];
    sort(t,t+N);
    cout << binSearch(0, 1000000000) << '\n';
}
/*
算法步骤：

1. 先将所有奶牛的到达时间 t 从小到大排序。

2. 二分答案 wait：
   wait 表示允许的最大等待时间。

3. 写判定函数 pos(wait)：
   判断在最大等待时间不超过 wait 的情况下，
   M 辆大巴是否能接走所有奶牛。

4. 贪心安排大巴：
   每辆大巴从当前还没上车的第一头奶牛开始装。
   继续往后装奶牛，直到出现以下任意一种情况：
   - 当前奶牛等待时间超过 wait；
   - 当前大巴人数超过容量 C。

5. 如果不能继续装，就启用下一辆大巴，
   并把当前奶牛作为新大巴的第一头奶牛。

6. 最后如果使用的大巴数量 wagons <= M，
   说明 wait 可行；否则不可行。

7. 因为 wait 越大越容易可行，具有单调性，
   所以用二分搜索找到最小可行 wait。

8. 输出这个最小 wait。
*/