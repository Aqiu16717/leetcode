#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        if (intervals.size() == 1) {
            return intervals;
        }
        // O(nlogn)
        std::sort(intervals.begin(), intervals.end(),
            [](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
            }); 
        vector<vector<int>> ret;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                ret.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            if (i == intervals.size() - 1) {
                ret.push_back({start, end});
            }
        } 
        return ret;
    }
};
/**
[1,3],[2,6],[8,10],[15,18]
|----|
1    3
  |------|
  2      6
            |------|
            8      10
                        |-----|
                        15    18
**/

class SolutionV2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        // O(nlogn)
        std::sort(intervals.begin(), intervals.end(),
            [](const vector<int>& lhs, const vector<int>& rhs) {
                //return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
                return lhs[0] < rhs[0];
            }); 
        vector<vector<int>> ret;
        // int start = intervals[0][0];
        // int end = intervals[0][1];
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= ret.back()[1]) {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            } else {
                ret.push_back(intervals[i]);
            }
        } 
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> x = {{1,4},{0,2},{3,5}};
    vector<vector<int>> ret = s.merge(x);
    cout << "expect:\t[0,5]" << endl;
    cout << "ret:\t";
    for (const auto& vec : ret) {
        cout << "[ ";
        for (const auto& elem : vec) {
            cout << elem << ", ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}