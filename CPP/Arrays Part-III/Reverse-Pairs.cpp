// Link: - https://leetcode.com/problems/reverse-pairs/

#include <iostream>
#include <vector>
using namespace std;

// Approach - 1 (Brute Force) Time: - O(n^2) Space: - O(1)
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > 2 * (long long)nums[j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Appraoch - 2 (Improvised Merge Sort) Time: - O(nlogn) Space: - O(n)
class Solution
{
    int merge(vector<int> &nums, int l, int mid, int r)
    {
        int i, j = mid + 1, k = 0, count = 0;

        for (i = l; i <= mid; i++)
        {
            while (j <= r && nums[i] > 2 * (long long)nums[j])
            {
                j++;
            }
            count += j - (mid + 1);
        }
        i = l;
        j = mid + 1;

        vector<int> sortedArr(r - l + 1);
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                sortedArr[k++] = nums[i++];
            }
            else
            {
                sortedArr[k++] = nums[j++];
            }
        }

        while (i <= mid)
        {
            sortedArr[k++] = nums[i++];
        }
        while (j <= r)
        {
            sortedArr[k++] = nums[j++];
        }

        for (int m = 0; m < sortedArr.size(); m++)
        {
            nums[l + m] = sortedArr[m];
        }
        return count;
    }

    int mergeSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        int count = 0, mid = l + (r - l) / 2;
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, r);

        count += merge(nums, l, mid, r);
        return count;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};