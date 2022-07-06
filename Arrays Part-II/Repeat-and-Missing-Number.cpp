// Link: - https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Ignore this :-)
class Solution
{
public:
    vector<int> repeatedNumber(const vector<int> &nums);
};

// Approach - 1 (Using Extra Space) Time: - O(n) Space: -O(1)
vector<int> Solution::repeatedNumber(const vector<int> &nums)
{
    unordered_map<int, int> present;
    int notPresent, twice;
    for (int i = 0; i < nums.size(); i++)
    {
        present[nums[i]]++;
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (present.count(i) == 0)
        {
            notPresent = i;
        }
        else if (present[nums[i - 1]] == 2)
        {
            twice = nums[i - 1];
        }
    }
    return {twice, notPresent};
}

// Approach - 2 - (Maths) Time: - O(n) Space - O(1)
vector<int> Solution::repeatedNumber(const vector<int> &nums)
{
    long long n = nums.size();
    long long s = n * (n + 1) / 2, p = n * (n + 1) * (2 * n + 1) / 6;
    for (int i = 0; i < nums.size(); i++)
    {
        s -= (long long)nums[i];
        p -= (long long)nums[i] * (long long)nums[i];
    }
    long long missing = (p / s + s) / 2;

    return {missing - s, missing};
}

// Approach - 3 - (Bit Manipulation) Time - O() Space - O()
vector<int> Solution::repeatedNumber(const vector<int> &nums)
{
    int xOr = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        xOr ^= nums[i - 1];
        xOr ^= i;
    }

    int setBit = xOr & ~(xOr - 1);
    int x = 0, y = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        if (nums[i - 1] & setBit)
        {
            x ^= nums[i - 1];
        }
        else
        {
            y ^= nums[i - 1];
        }

        if (i & setBit)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }
    int countX = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x)
        {
            countX++;
        }
    }
    if (countX > 0)
    {
        return {x, y};
    }

    return {y, x};
}
