#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int max_sum = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1], 0) + nums[i];
        max_sum = max(dp[i], max_sum);
    }

    return max_sum;
}

int main() {
    vector<int> nums;
    int ret;

    nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ret = maxSubArray(nums);
    cout << ret << endl;

    nums = {1};
    ret = maxSubArray(nums);
    cout << ret << endl;

    nums = {5, 4, -1, 7, 8};
    ret = maxSubArray(nums);
    cout << ret << endl;

    return 0;
}
