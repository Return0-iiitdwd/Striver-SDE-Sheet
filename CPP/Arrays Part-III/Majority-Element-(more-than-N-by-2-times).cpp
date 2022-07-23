//Link: - https://leetcode.com/problems/majority-element/submissions/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;

//Approach - 1 - (Brute force) Time: - O(n^2) Space: - O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++){
            int count = 0;
            for (int j = i; j < nums.size(); j++){
                if (nums[i] == nums[j]){
                    count++;
                }
            }
            if (count > majorityCount){
                ans = nums[i];
                majorityCount = count;
            }
        }
        return ans;
    }
};

//Approach - 2 (Using Hashmap) Time: - O(n) Space: - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementCount;
        int maxCount = 1, maxElement = nums[0];
        for (int i = 0; i < nums.size(); i++){
            elementCount[nums[i]]++;
            if (elementCount[nums[i]] > maxCount){
                maxCount = elementCount[nums[i]];
                maxElement = nums[i];
            }
        }
        return maxElement;
    }
};

//Approach - 3 (Sorting) Time: - O(nlogn) Space: - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//Approach - 4 (Divide and conquer) Time: - O(nlogn) Space: - O(logn)
class Solution {
    int helper(vector<int> &nums, int l, int h){
        if (l == h){
            return nums[l];
        }
        
        int mid = l + (h - l) / 2;
        int left = helper(nums, l, mid);
        int right = helper(nums, mid + 1, h);
        
        if (left == right){
            return left;
        }
        
        int leftCount = 0, rightCount = 0;
        for (int i = l; i <= h; i++){
            if (nums[i] == left){
                leftCount++;
            }
            else if (nums[i] == right){
                rightCount++;
            }
        }
        
        return rightCount > leftCount? right: left;
    }
public:
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

//Approach - 5 (Random) Time: - O(infinity) Space: - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2.0;
        while (true){
            srand(time(0));
            int candidate = nums[rand() % nums.size()], count = 0;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == candidate){
                    count++;
                }
            }
            if (count > majorityCount){
                return candidate;
            }
        }
        return -1;
    }
};

//Approach - 6 - (Boyer Moore’s Voting Algorithm) Time: - O(n) Space: - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (count == 0){
                ans = nums[i];
            }
            
            if (nums[i] == ans){
                count++;
            } 
            else{
                count--;
            }
        }
        return ans;
    }
};