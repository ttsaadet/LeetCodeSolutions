/*https://leetcode.com/problems/container-with-most-water/*/
#include "common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() -1;
        vector<int> areaVector;
        while(l < r){
            int maxH = height[l] < height[r] ? height[l] : height[r];
            areaVector.push_back(maxH * (r - l));
            if(height[l] <= height[r]) l++;
            else{r--; }
        }
        int max = 0;
        for(auto area : areaVector){
            if(area > max ) max = area;
        }
        return max;
    }
};

int main(){
    Solution s;
    return 0;
}