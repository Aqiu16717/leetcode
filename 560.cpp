/**
 * 560. Subarray Sum Equals K
 * Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        unordered_map<int, int> prefix_sum_count;
        prefix_sum_count[0] = 1;
        int ret = 0;
        int cur_prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur_prefix_sum += nums[i];
            if (prefix_sum_count.count(cur_prefix_sum - K)) {
                ret += prefix_sum_count[cur_prefix_sum - K];
            }
            prefix_sum_count[cur_prefix_sum]++;
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s;
    int ret = s.subarraySum(nums, 3);
    cout << ret << endl;
    return 0;
}
