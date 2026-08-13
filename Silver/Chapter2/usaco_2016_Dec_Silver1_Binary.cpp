#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int countLEQ(const vector<int>& list, int limit) {
    if (list[0] > limit) {
        return 0;
    }
    int min = 0;
    int max = list.size() - 1;
    // list[min] is guaranteed to be <= limit
    while (min != max) {
        int mid = (min + max + 1) / 2;
        if (list[mid] <= limit) {
            min = mid;
        } else {
            max = mid - 1;
        }
    }
    return min + 1;
}

int main() {
    ifstream br("haybales.in");
    ofstream pw("haybales.out");

    int n, q;
    br >> n >> q;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        br >> list[i];
    }

    sort(list.begin(), list.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        br >> a >> b;
        pw << countLEQ(list, b) - countLEQ(list, a - 1) << endl;
    }

    br.close();
    pw.close();

    return 0;
}
