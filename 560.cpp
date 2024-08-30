/**
 * 560. 和为 K 的子数组
 * 给你一个整数数组 nums 和一个整数 k ，
 * 请你统计并返回 该数组中和为 k 的子数组的个数 。
 * 子数组是数组中元素的连续非空序列。
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