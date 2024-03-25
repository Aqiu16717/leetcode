#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int current_tank = 0;
        int start = 0;
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            total_tank += gas[i] - cost[i];
            current_tank += gas[i] - cost[i];
            if (current_tank < 0) {
                current_tank = 0;
                start = i + 1;
            }
        }
        return total_tank < 0 ? -1 : start;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution s;
    int ret = s.canCompleteCircuit(gas, cost);
    assert(ret == 3);
    return 0;
}