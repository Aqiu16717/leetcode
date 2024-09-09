/**
 * 41.First Missing Positive
 * Given an unsorted integer array nums. Return the smallest positive integer
 * that is not present in nums.
 *
 * You must implement an algorithm that runs in O(n) time and uses O(1)
 * auxiliary space.
 */

#include <iostream>
#include <vector>

#include "common.h"

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0 || nums[i] > n) {
            continue;
        }
        tmp[nums[i] - 1] = nums[i];
    }
    // printVec(tmp);
    for (int i = 0; i < n; ++i) {
        if (tmp[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

// optimize space usuage
int firstMissingPositiveV2(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        // dead loop
        // [1,1]
        // while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    // printVec(tmp);
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    vector<int> nums;
    int ret;

    cout << "test0x0" << endl;
    nums = {1, 2, 0};
    printVec(nums);
    // ret = firstMissingPositive(nums);
    ret = firstMissingPositiveV2(nums);
    cout << ret << endl;

    cout << "test0x1" << endl;
    nums = {3, 4, -1, 1};
    printVec(nums);
    // ret = firstMissingPositive(nums);
    ret = firstMissingPositiveV2(nums);
    cout << ret << endl;

    cout << "test0x2" << endl;
    nums = {7, 8, 9, 11, 12};
    printVec(nums);
    // ret = firstMissingPositive(nums);
    ret = firstMissingPositiveV2(nums);
    cout << ret << endl;

    return 0;
}
