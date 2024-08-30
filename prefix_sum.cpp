#include <iostream>
#include <vector>

int rangeSum(std::vector<int>& prefix_sum, int start, int end) {
    if (start == 0) {
        return prefix_sum[end];
    }
    return prefix_sum[end] - prefix_sum[start - 1];
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "nums:" << std::endl;
    for (int num : nums) {
        std::cout << num << "\t";
    }
    std::cout << std::endl;
    int n = nums.size();
    std::vector<int> prefix_sum(n, 0);
    prefix_sum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }
    std::cout << "prefix_sum:" << std::endl;
    for (int i : prefix_sum) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    std::cout << "range sum [1,3]:" << std::endl;
    std::cout << rangeSum(prefix_sum, 1, 3);
    std::cout << std::endl;
    return 0;
}
