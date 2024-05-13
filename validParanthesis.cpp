#include "common.h"
#include <stack>


class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{') s1.push(c);
            
            else if(c == ')' && !s1.empty()) {
                char last = s1.top();
                if(last == '(') s1.pop();
                else return false;
            }
            else if(c == ']'&& !s1.empty() ) {
                char last = s1.top();
                if(last == '[') s1.pop();
                else return false;
            }
            else if(c == '}' && !s1.empty()) {
                char last = s1.top();
                if(last == '{') s1.pop();
                else return false;
            }
            else{
                return false;
            }
        }        
        if(s1.empty()) return true;
        else return false;
    }
};

int main(){
    Solution s;
    cout << s.isValid("[[{()}]]");
    return 0;
}