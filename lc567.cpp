/*https://leetcode.com/problems/permutation-in-string/ medium*/

#include "common.h"

class Solution {
public:
    bool isSame(uint16_t* arr1, uint16_t* arr2){
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        uint16_t charMap[26] = {0};
        
        for(auto c : s1)
            charMap[c - 'a']++;

        int l = 0;
        uint16_t s2CharMap[26] = {0};
        for(int r = 0; r < s2.length(); r++){
            s2CharMap[s2[r] - 'a']++;
            if(r - l +1 == s1.length()){
                if(isSame(charMap, s2CharMap))return true;
                else {
                    s2CharMap[s2[l] - 'a']--;
                    l++;
                }
            }
        }
        return false;
    }
};
int main(){
 Solution s;
 cout << s.checkInclusion("ab","eidbaooo");
}