#include<iostream>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // 1. 统计字符频率
        std::unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        // 2. 将频率和字符存储到容器中
        std::vector<std::pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

        // 3. 按照频率降序排序
        std::sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        // 4. 构建结果字符串
        std::string result;
        for (const auto& pair : freqVec) {
            result.append(pair.second, pair.first);
        }

        return result;
    }
};


