/*
https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a 
palindrome, and false otherwise.
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;


class Solution {
private:
    bool check(std::string s){
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int i = 0;
        int j = s.length() - 1;
        while(s[i] == s[j]){
            i++;
            j--;
            if(i >= j) return true;
        }
        return false;
    }
public:
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if(x == 0) return true;
        else{
            std::string s = std::to_string(x);
            return check(s);
        }
    }
};


int main(){
    Solution s;
    
    assert(s.isPalindrome(100001));
    assert(s.isPalindrome(1221));
    assert(s.isPalindrome(2552));
    assert(s.isPalindrome(95455459));
    assert(s.isPalindrome(123321));
    assert(s.isPalindrome(5885));
}