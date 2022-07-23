//Link: - https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Approach - 1 (Hashmap) Time: - O(n) Space: - O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> numCount;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            numCount[nums[i]]++;
        }
        
        for (auto num : numCount){
            if (num.second > nums.size() / 3){
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};

//Approach - 2 (Extended Boyer Moore’s Voting Algorithm) Time: - O(n) Space: - O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = -1, cand2 = -1, count1 = 0, count2 = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            if (cand1 == nums[i]){
                count1++;
            }
            else if (cand2 == nums[i]){
                count2++;
            }
            else if (count1 == 0){
                cand1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0){
                cand2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        
        for (int i = 0; i <  nums.size(); i++){
            if (nums[i] == cand1){
                count1++;
            }
            else if (nums[i] == cand2){
                count2++;
            }
        }
        
        if (count1 > nums.size() / 3){
            ans.push_back(cand1);
        }
        if (count2 > nums.size() / 3){
            ans.push_back(cand2);
        }
        
        return ans;
    }
};