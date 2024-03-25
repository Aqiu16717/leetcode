#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reach = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_reach = max(max_reach, nums[i] + i);
            if (i == end) {
                end = max_reach;
                ++step;
            }
        }
        return step;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution s;
    int ret = s.jump(nums);
    assert(ret == 2);
    return 0;
}