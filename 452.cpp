#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        std::sort(points.begin(), points.end(),
            [](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[1] < rhs[1];
            });
        int end = points[0][1];
        int ret = 1;
        for (int i = 1; i < points.size(); ++i) {
            /**
            *  |------|
            *            |------|
            **/
            if (end < points[i][0]) {
                ++ret;
                end = points[i][1];
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int ret = s.findMinArrowShots(points);
    assert(ret == 2);
    return 0;
}