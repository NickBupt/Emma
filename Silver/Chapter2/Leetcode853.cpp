#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> time(target + 1);
        for (int i = 0; i < position.size(); i++) {
            time[target - position[i]] = 1.0f * (target - position[i]) / (1.0f * speed[i]);
        }

        vector<double> st;
        for (auto t : time) {
            if (t > 0 && (st.empty() || t > st.back())) st.push_back(t);
        }

        return st.size();
    }
};


