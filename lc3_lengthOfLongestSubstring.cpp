#include "common.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        if(s.length() == 1) return 1;
        
        int l = 0;
        int len = 0;
        int maxLen = 0;
        for(int r = 0; r < s.length();r++){
            auto it = map.find(s[r]);
            if(it == map.end()){
                map[s[r]] = r;
            }
            else{
                int newL = it->second + 1;
                for(int i = l; i < newL; i++){
                    map.erase(s[i]);
                }
                l = newL;
                map[s[r]] = r;
            }
            len = r - l + 1;
            if(len > maxLen) maxLen = len;
        }
        return maxLen;
    }
};
int main(){
    Solution s;
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
     assert(s.lengthOfLongestSubstring("abba") == 2);
    assert(s.lengthOfLongestSubstring("dvdk") == 3);
}