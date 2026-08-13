#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        bool used[nums.size()];
        memset(used, false, nums.size());
        vector<int> curResult;
        dfs(nums, 0, used, curResult);
        return results;
    }

    void dfs(vector<int>& nums, int cur, bool used[], vector<int>& curResult){
        if (cur == nums.size()){
            results.push_back(curResult);
            return;
        }

        set<int> repeated;
        for (int i = 0; i < nums.size(); ++i){
            if (!used[i] && repeated.find(nums[i]) == repeated.end()){
                used[i] = true;
                curResult.push_back(nums[i]);
                repeated.insert(nums[i]);
                dfs(nums, cur + 1, used, curResult);
                curResult.pop_back();
                used[i] = false;
            }
        }
    }
};

