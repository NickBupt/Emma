#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 商店类，存储每个商店的购买量和价格
struct Shop {
    long long quantity; // 商店愿意购买的牛奶量
    long long price;    // 商店的购买价格（每加仑）

    //构造函数
    Shop(long long q, long long p) : quantity(q), price(p) {}
    // 为了按价格从高到低排序，重载小于号运算符
    bool operator<(const Shop& other) const {
        return price > other.price; // 注意：'>' 表示降序排序
    }
};

// 对整数数组进行降序排序
void sort_desc(vector<int>& v) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
}

int main() {
    ifstream br("rental.in");
    ofstream pw("rental.out");

    int n, m, r;
    br >> n >> m >> r;

    vector<int> milkProduced(n);
    for(int i = 0; i < n; i++) {
        br >> milkProduced[i];
    }
    sort_desc(milkProduced); // 奶牛产奶量从大到小排序 O(nlogn)

    vector<Shop> shops;
    for(int i = 0; i < m; i++) {
        long long quantity, price;
        br >> quantity >> price;
        shops.emplace_back(quantity, price);
    }
    sort(shops.begin(), shops.end()); // 商店按价格从高到低排序 O(mlogm)

    vector<long long> maxProfit(n + 1, 0);
    {
        int index = 0;
        for(int i = 0; i < n; i++) {
            maxProfit[i + 1] = maxProfit[i];
            while(index < m && milkProduced[i] > 0) {
                // 计算当前奶牛可以卖给商店的牛奶量
                long long use = min((long long)milkProduced[i], shops[index].quantity);
                maxProfit[i + 1] += use * shops[index].price; // 增加收益
                milkProduced[i] -= use;           // 减少奶牛剩余的牛奶量
                shops[index].quantity -= use;     // 减少商店的购买需求
                if(shops[index].quantity == 0) {
                    index++; // 当前商店购买量已满，移动到下一个商店
                }
            }
        }
    }

    vector<int> rental(r);
    for(int i = 0; i < r; i++) {
        br >> rental[i];
    }
    sort_desc(rental); // 租赁价格从高到小排序 O(rlogr)
    {
        int a = n - 1; // 从最后一头奶牛开始
        int rI = 0;    // 租赁数组的索引
        long long rentalSoFar = 0;
        while(a >= 0 && rI < r) {
            rentalSoFar += rental[rI]; // 累加租赁收益
            maxProfit[a] += rentalSoFar; // 更新总收益
            rI++;
            a--;
        }
    }

    long long ret = 0;
    for(auto out : maxProfit) {
        ret = max(ret, out); // 找到最大收益
    }
    pw << ret << endl;
    pw.close();
    return 0;
}
