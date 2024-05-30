#include "common.h"
#include <assert.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size() -1;

        while(l <= r){
            int m = (l + r)/2;
            if(target < nums[m]) r = m - 1;
            else if(target > nums[m]) l = m + 1;
            else return m;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> vec1{-1,0,2,4,6,8};
    assert(s.search(vec1, 4) == 3);
    
    vector<int> vec2{-1};
    assert(s.search(vec2, -1) == 0);
    
        vector<int> vec3{-1};
    assert(s.search(vec3, 0) == -1);
    return 0;
}