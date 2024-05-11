/*https://leetcode.com/problems/longest-consecutive-sequence/description/*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        set<int> numset(nums.begin(), nums.end());
        int max = 0;
        int length = 0;
        for(auto num: numset){
            length = 0;
            
            if(numset.find(num - 1) == numset.end()){
                length++;
                int key = num+1;
                while (numset.find(key++) != numset.end())
                {
                    length++;
                }
            }
            if(length > max) max = length;
        }
        return max;
       
    }
};

int main(){
    Solution s;
    vector<int> vec{0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(vec);
    return 0;
}