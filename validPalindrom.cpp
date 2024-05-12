// https://leetcode.com/problems/valid-palindrome/
#include "common.h"
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            while(!isalnum(s[l]) && l < r) l++;
            while(!isalnum(s[r]) && r > l) r--;
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;    
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}