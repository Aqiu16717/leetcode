#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
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

    vector<int> nums = {1,2,3,1};
    int ret = s.rob(nums);
    assert(ret == 4);

    return 0;
}
