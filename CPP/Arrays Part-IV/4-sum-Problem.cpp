// Link: - https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

// Approach 1 (Brute force) Time: - O(n^4) Space: - O(4 * no-of-quadruplets)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> uniqueAns;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    for (int l = k + 1; l < nums.size(); l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            uniqueAns.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        for (auto x : uniqueAns)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

// Approach - 2 (3 loops + binary Search) Time: - O(n^3 logn) SSpace: - O(4 * no-of-quadruplets)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> quads;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    int low = k + 1;
                    int high = nums.size() - 1;
                    long long int x = (long long)target - nums[i] - nums[j] - nums[k];
                    while (low <= high)
                    {
                        int mid = low + (high - low) / 2;
                        if (nums[mid] == x)
                        {
                            quads.insert({nums[i], nums[j], nums[k], (int)x});
                            break;
                        }
                        else if (nums[mid] > x)
                        {
                            high = mid - 1;
                        }
                        else
                        {
                            low = mid + 1;
                        }
                    }
                }
            }
        }
        for (auto &quad : quads)
        {
            ans.push_back(quad);
        }

        return ans;
    }
};

// Approach - 3 (2 loops + 2 pointer) Time: - O(n^3) Space: - O(4 * no-of-quadruplets)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> quads;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long x = (long long)target - nums[i] - nums[j];
                int low = j + 1, high = nums.size() - 1;
                while (low < high)
                {
                    int sum = nums[low] + nums[high];
                    if (nums[low] + nums[high] == x)
                    {
                        quads.insert({nums[i], nums[j], nums[low], nums[high]});
                        int lowNo = nums[low], highNo = nums[high];
                        while (low < nums.size() && nums[low] == lowNo)
                        {
                            low++;
                        }
                        while (high >= j + 1 && nums[high] == highNo)
                        {
                            high--;
                            ;
                        }
                    }
                    else if (sum < x)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }

                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                {
                    j++;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        for (auto &quad : quads)
        {
            ans.push_back(quad);
        }

        return ans;
    }
};