#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
        {
            return 0;
        }
        int l = 0;
        int maxProfit = 0;
        for(int r = 1; r < prices.size(); r++){
            if(prices[r] < prices[l]) {
                l = r;
                continue;
            }
            int profit = prices[r] -prices[l];
            if(profit > maxProfit) maxProfit = profit;
        }
        
        return maxProfit;
    }
};



int main(){

}