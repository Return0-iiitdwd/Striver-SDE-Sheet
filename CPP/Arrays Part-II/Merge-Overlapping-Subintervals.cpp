//Link: - https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Approach 1 {sorting} Time: - O(nlogn) Space: - O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
    ans.push_back({start, end});
    return ans;
    }
};

//One more approach using Graph