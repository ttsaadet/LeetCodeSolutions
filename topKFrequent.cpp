/*https://leetcode.com/problems/top-k-frequent-elements/*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //count each number in array
        unordered_map<int, int> countOfEachNumber;
        for(int i = 0; i < nums.size(); i++){
            countOfEachNumber[nums[i]]++;
        }

        //place them to map according to theirs count
        map<int, vector<int>> numbersOfEachCount;
        for (auto& it: countOfEachNumber)
        {
            numbersOfEachCount[it.second].push_back(it.first);;  
        }
        
        //fill return vector from top most k element in map
        int index=0;
        vector<int> topkfreqVec;
        for (auto iter= numbersOfEachCount.crbegin(); index < k; ++iter)
        {
            for(auto number : iter->second){
                topkfreqVec.push_back(number);
                index++;
                if(index > k){
                    break;
                }
            }
        }

        return topkfreqVec;
    }
};



int main(){
    Solution s;
    vector<int> vec{1,1,1,3,4,5,5,6,1,3,3};
    vector<int> ret = s.topKFrequent(vec,2);
    cout << ret[0];
    cout << ret[1];
    
    return 0;
}