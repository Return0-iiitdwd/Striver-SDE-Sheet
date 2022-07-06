// Link: - https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Appraoch - 1 (Brute Force) Time: - O((m + n)log(m + n)) Space: - O(1)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

// Appraoch - 2 (Using Extra Space) Time: - O(m + n) Space: - O(m + n)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i++]);
            }
            else
            {
                temp.push_back(nums2[j++]);
            }
        }

        while (i < m)
        {
            temp.push_back(nums1[i++]);
        }

        while (j < n)
        {
            temp.push_back(nums2[j++]);
        }

        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = temp[i];
        }
    }
};

// Approach - 3 (InPlace) Time: - O(mn) Space: - O(1)
class Solution
{
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (nums2.size() == 0)
        {
            return;
        }

        for (int i = 0; i < m; i++)
        {
            if (nums2[0] < nums1[i])
            {
                swap(nums2[0], nums1[i]);
            }

            int temp = nums2[0], j;
            for (j = 1; j < n && nums2[j] < temp; j++)
            {
                nums2[j - 1] = nums2[j];
            }

            nums2[j - 1] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
    }
};


//Approach - 4 (Optimal) Time: - O((m + n)log(m + n)) Space: - O(1)
class Solution {
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = 0; i < n; i++){
            nums1[i + m] = nums2[i];
        }
        //We need to take gap =  ceil((m + n)/ 2)
        //Ceil(1 / 2. 0) = 1, this may cause infinite loop, so we wrote the increment differently.
        for (int gap = (m + n + 1) / 2; gap > 0; gap = (gap != 1)? ceil(gap / 2.0): 0){
            for (int i = 0, j = gap; j < m + n; i++, j++){
                if (nums1[i] > nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
            }
        }
    }
};