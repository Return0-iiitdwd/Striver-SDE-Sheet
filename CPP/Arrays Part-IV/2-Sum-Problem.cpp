//Link: - https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Approach - 1 (Brute Force) Time: - O(n^2) Space: - O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

//Approach - 2 (Two Pointers) Time: - O(nlogn) Space: - O(1)
//Note: - If array is sorted time complexity will be O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> newNums(nums.size());
        for (int i = 0; i < nums.size(); i++){
            newNums[i] = {nums[i], i};
        }
        int i = 0, j = nums.size() - 1;
        sort(newNums.begin(), newNums.end());
        while (i < j){
            int sum = newNums[i].first + newNums[j].first;
            if (sum == target){
                return {newNums[i].second, newNums[j].second};
            }
            else if (sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1, -1};
    }
};

//Approach - 3 - (HashMaps) Time : - O(n) Space: - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        
        for (int i = 0; i < nums.size(); i++){
            if (numToIndex.count(target - nums[i])){
                return {i, numToIndex[target - nums[i]]};
            }
            numToIndex[nums[i]] = i;
        }
        return {-1, -1};
    }
};