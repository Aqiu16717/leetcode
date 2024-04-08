#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(helper(nums1), helper(nums2));
    }

    int helper(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};

int main()
{
    Solution s;

    vector<int> nums = {0};
    int ret = s.rob(nums);
    assert(ret == 0);

    nums = {2,3,2};
    assert(s.rob(nums) == 3);

    return 0;
}
