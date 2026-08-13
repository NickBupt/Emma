#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }

        sort(points.begin(),points.end(),[](const auto &a,const auto    &b){
            return a[1]<b[1];
        });

        int arrows = 1;
        int arrow_pos = points[0][1];

        for(const vector<int>& ballon:points){
            if(ballon[0]>arrow_pos){
                arrow_pos = ballon[1];
                arrows++;
            }
        }

        return arrows;
    }
};
