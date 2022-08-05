// Link: - https://www.interviewbit.com/problems/subarray-with-given-xor/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &A, int B);
};

// Appraoch - 1 (Brute force) Time: - O(n^2) Space: - O(1)
int Solution::solve(vector<int> &A, int B)
{
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int xOr = 0;
        for (int j = i; j < A.size(); j++)
        {
            xOr ^= A[j];
            if (xOr == B)
            {
                ans++;
            }
        }
    }
    return ans;
}

// Approach - 2 (Prefix) Time: - O(n) Space: - O(n)
int Solution::solve(vector<int> &A, int B)
{
    unordered_map<int, int> countPrefix;
    int xr = 0;
    long long ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        xr ^= A[i];
        if (xr == B)
        {
            ans++;
        }
        int temp = B ^ xr;
        if (countPrefix.count(temp) > 0)
        {
            ans = ans + countPrefix[temp];
        }
        countPrefix[xr]++;
    }
    return ans;
}
