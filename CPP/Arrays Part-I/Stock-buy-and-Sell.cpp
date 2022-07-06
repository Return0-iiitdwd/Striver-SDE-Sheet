//Line: - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
using namespace std;


//Approach - 1 - (Brute Force) Time: - O(n^2) Space: - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i++){
            for (int j = i + 1; j < prices.size(); j++){
                if (prices[j] - prices[i] > ans){
                    ans = prices[j] - prices[i];
                }
            }
        }
        return ans;
    }
};


//Approach - 2 - (Converting to maximum subarray sum) Time: - O(n) Spce: - O(1)
//We have used kadane's algorithm for calculating max subarray sum
class Solution {
    int maxSubarraySum(vector<int>& nums){
         int ans = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > ans)
            {
                ans = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<int> change(1, 0);
        
        for (int i = 1; i < prices.size(); i++){
            change.push_back(prices[i] - prices[i - 1]);
        }
        
        int ans = maxSubarraySum(change);
        return ans;
    }
};


//Approach - 3 - (DP) Time: - O(n) Space: - O(n)
//Traversing from front
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp;
        dp.push_back(prices[0]);
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < dp[i - 1]){
                dp.push_back(prices[i]);
            }
            else{
                dp.push_back(dp[i - 1]);
            }
        }
        int ans = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] - dp[i] > ans){
                ans = prices[i] - dp[i];
            }
        }
        
        return ans;
    }
};

//Traversing from back
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        dp[prices.size() - 1] = prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i--){
            if (prices[i] > dp[i + 1]){
                dp[i] = prices[i];
            }
            else{
                dp[i] = dp[i + 1];
            }
        }
        
        int ans = 0;
        for (int i = prices.size() - 2; i >= 0; i--){
            if (dp[i] - prices[i] > ans){
                ans = dp[i] - prices[i];
            }
        }
        
        return ans;
    }
};


//Approach - 4: - (Space optimised DP) Time: - O(n) Space: - O(1)
//Traversing from front
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], ans = 0;
        
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < min){
                min = prices[i];
            }
            if (prices[i] - min > ans){
                ans = prices[i] - min;
            }
        }
        
        return ans;
    }
};

//Traversing from back
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = prices[prices.size() - 1];
        int ans = 0;
        for (int i = prices.size() - 2; i >= 0; i--){
            if (prices[i] > max){
                max = prices[i];
            }
            if (max - prices[i] > ans){
                ans = max - prices[i];
            }
        }
        return ans;
    }
};