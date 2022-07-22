//Link: - https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>
using namespace std;

//Approach - 1 (Brute Force) Time: - O(mn) Space: - O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

//Approach - 2 (Binary Search) Time: - O(log(mn)) Space: - O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() * matrix[0].size() - 1;
        int m = matrix.size(), n = matrix[0].size();
        while (low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            
            if (matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};