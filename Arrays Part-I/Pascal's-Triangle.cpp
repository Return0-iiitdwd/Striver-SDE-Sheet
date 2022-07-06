//Link: - https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++){
            vector<int> row;
            for (int j = 0; j <= i; j++){
                
                //First and last element in each row should be 1
                if (j == 0 || j == i){
                    row.push_back(1);
                }
                
                //All other element will be some of element direclty above and one left of the above
                else {
                    row.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};