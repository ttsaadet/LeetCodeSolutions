/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 
*/
/*
    Author: Taha Tolga Saadet
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int remained = target - nums[i];
            auto it = map.find(remained);
            if(it != map.end() && i != it->second){// if number is found and if not equal with itself
                return {i, it->second};
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<int> vec{3,5,11,18};
    vector<int> res = s.twoSum(vec,29);
    cout << res[0] << " " << res[1];
    return 1;
}