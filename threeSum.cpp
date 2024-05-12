/*https://leetcode.com/problems/3sum/*/
#include "common.h"
#include <set>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(auto i = 0; i < nums.size()-1 ; i++){
            if(i >= 1){
                if(nums[i] == nums[i-1]) continue;
            }
            int l = i +1;
            int r = nums.size() -1;
            while (l < r)
            {
                if(nums[l] + nums[r] > -nums[i]) r--;
                else if(nums[l] + nums[r] < -nums[i]) l++;
                else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l-1] && l < r )
                    {
                        l++;
                    }
                }
                
            }
        }            
        return result;       
    }
};


int main(){
    Solution s;
    vector<int> vec{1,2,1,1,2,4,-3,-5};
    s.threeSum(vec);
    return 0;
}