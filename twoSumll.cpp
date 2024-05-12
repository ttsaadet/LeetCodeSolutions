
#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int maxIndex = numbers.size();
        if(numbers[0] > 0){
            auto it = lower_bound(numbers.begin(), numbers.end(), target);
            maxIndex = distance(numbers.begin(), it);
        }   

        int leftP = 0;
        int rightP = maxIndex;
        while(leftP < rightP){
            int sum = numbers[leftP] + numbers[rightP];
            if(sum < target) leftP++;

            else if(sum > target) rightP--;

            else return {leftP+1 , rightP +1};
        }

        return {0,0};

    }
};


int main(){
    Solution s;
    vector<int> vec{0,2,25,31,52};
    vector<int> res = s.twoSum(vec,27);
    cout << res[0]<< " " << res[1];
    return 0;
}