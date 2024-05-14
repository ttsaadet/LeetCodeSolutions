/*https://leetcode.com/problems/daily-temperatures/description/*/

#include"common.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> dayVec(temperatures.size(), 0);
        stack<int> tempStack;
        stack<int> indexStack;
        tempStack.push(temperatures[0]);
        indexStack.push(0);
        for(int i = 1; i < temperatures.size(); i++){
            
            while(!tempStack.empty()&& temperatures[i] > tempStack.top()){
                
                dayVec[indexStack.top()] = i - indexStack.top();
                tempStack.pop();
                indexStack.pop();
            }
            tempStack.push(temperatures[i]);
            indexStack.push(i);
        }
        return dayVec;        
    }
};


int main(){
    Solution s;
    vector<int> in{73,74,75,71,69,72,76,73};
    vector<int> out;
    out = s.dailyTemperatures(in);
    for(auto o:out){
        cout << o << " ";
    }
}
