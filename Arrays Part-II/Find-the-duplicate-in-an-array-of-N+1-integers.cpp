// link: - https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Approach - 1 - (Brute Force) Time: - O(n^2) Space: - O(1)
class Solution
{


public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

// Approach - 2 - (Sorting) Time: - (nlogn) Space: - O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// Approach - 3 (Haspmaps) Time: - O(n) Space: - O(n)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> present;

        for (int i = 0; i < nums.size(); i++)
        {
            if (present[nums[i]])
            {
                return nums[i];
            }
            present[nums[i]] = true;
        }
        return -1;
    }
};

// Approach - 4 (Using Negative Marking) Time: - O(n) Space: - O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i] > 0 ? nums[i] : -1 * nums[i];
            if (nums[x] < 0)
            {
                return x;
            }
            nums[x] *= -1;
        }
        return -1;
    }
};

// Approach - 5 - (Array as hashmap) Time: - O(n) Space: - O(1)
// Recursive Time: - O(n) Space: - O(n)
class Solution
{
    int helper(vector<int> &nums, int cur)
    {
        if (cur == nums[cur])
        {
            return cur;
        }
        int nxt = nums[cur];
        nums[cur] = cur;

        return helper(nums, nxt);
    }

public:
    int findDuplicate(vector<int> &nums)
    {
        return helper(nums, 0);
    }
};

// Iterative Time: - O(n) Space: - O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        while (nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }

        return nums[0];
    }
};

// Approach - 6 - (Binary Search) Time: - O(n logn) Space: - O(1)
class Solution
{
    int numLessThanEqualTo(vector<int> &nums, int val)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= val)
            {
                count++;
            }
        }
        return count;
    }

public:
    int findDuplicate(vector<int> &nums)
    {
        int l = 1, h = nums.size() - 1;
        int ans = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (numLessThanEqualTo(nums, mid) > mid)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// Approach - 7 - (Bit manipulation) Time: - O(nlogn) Space: - O(1)
class Solution
{
    int max(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > ans)
            {
                ans = nums[i];
            }
        }
        return ans;
    }

    int maxBit(int n)
    {
        int bits = 0;
        while (n > 0)
        {
            n /= 2;
            bits++;
        }
        return bits;
    }

public:
    int findDuplicate(vector<int> &nums)
    {
        int ans = 0;
        int bitMax = maxBit(max(nums));

        for (int bit = 0; bit < bitMax; bit++)
        {
            int mask = (1 << bit);
            int numsBit = 0, totalBit = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (i & mask)
                {
                    totalBit++;
                }

                if (nums[i] & mask)
                {
                    numsBit++;
                }
            }

            if (numsBit > totalBit)
            {
                ans |= mask;
            }
        }
        return ans;
    }
};

// Approach - 8 - (Floyd's algorithm - tortoise and hare) Time: - O(n) Space - O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        //Tortoise - slow (moves one step), hare - fast (moves two steps)...
        int tortoise = nums[0], hare = nums[0];

        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (hare != tortoise);


        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};