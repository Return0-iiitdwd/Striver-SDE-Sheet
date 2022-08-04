//Link: - https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//Approach - 1 (Brute Force) Time: - O(n^2) Space: - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++){
            unordered_map<char, bool> isPresent;
            for (int j = i; j <= s.length(); j++){
                if (j == s.length() || isPresent.count(s[j])){
                    ans = max(ans, j - i);
                    break;
                }
                isPresent[s[j]] = true;
            }
        }
        return ans;
    }
};

//Approach - 2 (Sliding window) Time: - O(n) Space: - O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ans = 0, i = 0;
        unordered_map<char, int> cnt;
        while (i < s.length()){
            if (cnt[s[i]] == 0){
                ans = max(ans, i - start + 1);
                cnt[s[i]]++;
                i++; 
            }
            else{
                cnt[s[start]]--;
                start++;
            }
        }
        return ans;
    }
};
