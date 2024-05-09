/*
https://leetcode.com/problems/valid-anagram/description/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
/*
    Author:Taha Tolga Saadet
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        const uint8_t char_count_in_english = 26;
        const uint8_t offset = 'a';
        uint16_t arr[char_count_in_english] = {0};

        if(s.length() != t.length()) return false;

        for(int i = 0; i < s.length(); i++){
            arr[s[i] - offset]++;
        }

        for(int i = 0; i < t.length(); i++){
            arr[t[i] - offset]--; 
        }

        for (int i = 0; i < char_count_in_english; i++)
        {
            if(arr[i] != 0){
                return false;
            }
        }
        return true;
        
    }
};


int main(){
    Solution s;
    cout << s.isAnagram("asdfd","fdcsad");
    return 0;
}