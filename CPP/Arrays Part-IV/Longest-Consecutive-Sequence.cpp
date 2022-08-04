// Link: - https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Approach - 1 (Brute Force - Sorting) Time: - O(nlog(n)) Space: - O(1)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                count++;
            }
            else if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};

// Approach - 2 (Hashmaps) Time: - O(n) Space: - O(1)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, char> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = true;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]])
            {
                int count = 1;
                mp[nums[i]] = false;
                int num = nums[i];
                while (mp[num + 1])
                {
                    count++;
                    num++;
                    mp[num] = false;
                }
                num = nums[i];
                while (mp[num - 1])
                {
                    count++;
                    num--;
                    mp[num] = false;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};