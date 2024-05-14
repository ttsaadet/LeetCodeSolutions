#include "common.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        stack<int>number;
        for(auto token: tokens){
            if(token == "+"){
                int right = number.top();
                number.pop();
                int left = number.top();
                number.pop();
                number.push(left + right);
            }
            else if(token == "-"){
                int right = number.top();
                number.pop();
                int left = number.top();
                number.pop();
                number.push(left - right);
            }
            else if(token == "*"){
                int right = number.top();
                number.pop();
                int left = number.top();
                number.pop();
                number.push(left * right);
            }
            else if(token == "/"){
                int right = number.top();
                number.pop();
                int left = number.top();
                number.pop();
                number.push(left / right);
            }
            else{
                number.push(atoi(token.c_str()));
            }
        }    

        return number.top();
    }
};

