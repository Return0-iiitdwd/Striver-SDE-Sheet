//Link: - https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>
using namespace std;

//Approach - 1 (Brute Force) Time: - (Exponential) Space: - (Exponential)
class Solution {
    int helper(int row, int col, int m, int n){
        if (row == m - 1 && col == n - 1){
            return 1;
        }
        if (row >= m || col >= n){
            return 0;
        }
        
        return helper(row + 1, col, m, n) + helper(row, col + 1, m, n);
        
    }
public:
    int uniquePaths(int m, int n) {
        return helper(0, 0, m, n);
    }
};

//Approach - 2 (DP) Time: - O(mn) Space: - O(mn)
//Recursive
class Solution {
    int helper(int row, int col, int m, int n, vector<vector<int>> &dp){
        if (row == m - 1 && col == n - 1){
            return 1;
        }
        if (row >= m || col >= n){
            return 0;
        }
        
        if (dp[row][col] != -1){
            return dp[row][col];
        }
        
        dp[row][col] = helper(row + 1, col, m, n, dp) + helper(row, col + 1, m, n, dp);
        
        return dp[row][col];
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, dp);
    }
};

//Iterative
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < n; i++){
            dp[m - 1][i] = 1;
        }
        for (int i = 0; i < m; i++){
            dp[i][n - 1] = 1;
        }
        for (int i = m - 2; i >= 0; i--){
            for (int j = n - 2; j >= 0; j--){
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};

//Note: - Iterative is better then recursive

//Approach - 3 (Combinatorics) Time: - O(m - 1) or O(n - 1) Space: - O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        double ans = 1;
        int r = n - 1;
        for (int i = 1; i <= r; i++){
            ans = ans * (N - r + i) / i;
        }
        
        return (int)ans;
    }
};
