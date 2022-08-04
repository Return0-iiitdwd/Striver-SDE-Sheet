// Link: - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: - 1 (Brute Force) Time: - O(n^2) Space: - O(1)
class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += A[j];
                if (sum == 0)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};


//Approach - 2 (hashMaps) Time: - O(n) Space: - O(n)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans = 0, sum = 0;
        unordered_map<int, int> sumIndex;
        sumIndex[0] = -1;
        for (int i = 0; i < n; i++){
            sum += A[i];
            if (sumIndex.count(sum)){
                ans = max(ans, i - sumIndex[sum]);
            }
            else{
                sumIndex[sum] = i;
            }
        }
        return ans;
    }
};

