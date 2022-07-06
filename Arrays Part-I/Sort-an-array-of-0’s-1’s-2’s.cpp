//Link: - https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>
using namespace std;


//Approach - 1 Time: - O(n) Space: - O(1) (Two Iteration Required)
class Solution {
public:
    void sortColors(vector<int>& nums) {
     int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                count0++;
            }
            else if (nums[i] == 1){
                count1++;
            }
            else{
                count2++;
            }
        }
        int i = 0;
        while (count0--){
            nums[i++] = 0;
        }
        while (count1--){
            nums[i++] = 1;
        }
        while (count2--){
            nums[i++] = 2;
        }
    }
};


//Approach - 2 Time: - O(n) Space: - O(1)
class Solution {
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while (i <= k){
            if (nums[i] == 0){
                swap(nums[i++], nums[j++]);
            }
            else if (nums[i] == 2){
                swap(nums[i], nums[k--]);
            }
            else{
                i++;
            }
        }
    }
};