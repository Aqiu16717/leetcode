#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Break down the problem.
 * 1. height
 * 2. position
 * Solve one problem at a time.
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret;
        std::sort(people.begin(), people.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] != rhs[0] ? lhs[0] > rhs[0] : lhs[1] < rhs[1];
        });

        for (int i = 0; i < people.size(); ++i) {
            ret.insert(ret.begin() + people[i][1], people[i]);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> ret = s.reconstructQueue(people);
    for (auto x : ret) {
        cout << x[0] << "," << x[1] << "\t";
    }
    cout << endl;

    return 0;
}