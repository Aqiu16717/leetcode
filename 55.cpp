#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > max_reach) {
                return false;
            }
            max_reach = max(max_reach, nums[i] + i);
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ret = s.canJump(nums);
    std::cout << ret << std::endl;
    return 0;
}