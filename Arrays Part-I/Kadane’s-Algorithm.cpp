// Link: - https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
using namespace std;

// Approach - 1 - (Brute Force - Calculating sum of all subarrays) Time: - O(n^3) Space: - O(1)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if (sum > ans)
                {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};

// Approach - 2 - (Optimised Brute Force) Time: - O(n*2) Space: - O(1)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum > ans)
                {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};

// Approach 3 - (Divide and Conquer) Time: - O(nlogn) Space: - O(logn)
class Solution
{
    int helper(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return nums[l];
        }

        int mid = l + (r - l) / 2;

        // Left Sum Subarray
        int lss = helper(nums, l, mid);

        // Right Sum Subarray
        int rss = helper(nums, mid + 1, r);

        // Cross Sum Subarray
        int sumL = nums[mid], sumR = nums[mid + 1], i = mid, j = mid + 1, sum = 0;
        while (i >= l)
        {
            sum += nums[i--];
            if (sum > sumL)
            {
                sumL = sum;
            }
        }
        sum = 0;
        while (j <= r)
        {
            sum += nums[j++];
            if (sum > sumR)
            {
                sumR = sum;
            }
        }
        int css = sumL + sumR;

        return max(lss, max(css, rss));
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Approach 4 - (Kadane's Algorithm) Time: - O(n) Space: - O(1)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
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
};
