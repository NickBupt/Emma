#include <iostream>
using namespace std;

struct node{
    int x;
    int y;
};

bool sortByDesc(int a, int b) {
    return a > b;//降序排列
}

bool compare(node a, node b) {
    if (a.x == b.x)
        return a.y > b.y;//纵坐标降序
    return b.x > a.x;//横坐标升序
}

/*
 * bool：返回类型，表示比较的结果是 true 或 false。
operator<：表示重载 < 运算符。
const node2& p：参数，表示要与当前对象（this）进行比较的另一个 node2 对象。
const：表示该函数不会修改当前对象的数据。
 */
struct node2 {
    int x;
    int y;
    bool operator< (const node2& p) const {
        if (x == p.x)
            return y > p.y;
        else
            return p.x > x;
    }
};

int main()
{
    vector<int> v(10);
    for (int i = 0; i < 10; ++i)
        v[i] = i + 1;//1 2 3 4 5 6 7 8 9 10

    sort(v.begin(), v.end(), sortByDesc);
    for (auto item : v)
        cout << item << " ";
    cout << endl;


    vector<node> v2(10);
    for (int i = 0; i < 10; ++i) {
        v2[i].x = i % 5;
        v2[i].y = i % 3;
    }

    sort(v2.begin(), v2.end(), compare);
    sort(v2.begin(), v2.end(), [](node a, node b){return a.x == b.x ? a.y > b.y : b.x > a.x;});

    for (auto item : v2)
        cout << item.x << " " << item.y << endl;

    vector<node2> v3(10);
    for (int i = 0; i < 10; ++i) {
        v3[i].x = i % 5;
        v3[i].y = i % 3;
    }

    sort(v3.begin(), v3.end());
    for (auto item : v3)
        cout << item.x << " " << item.y << endl;

}