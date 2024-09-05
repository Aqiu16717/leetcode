/*
1. Two Sum
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> dic;

    for (int i = 0; i < nums.size(); ++i) {
        if (dic.count(target - nums[i])) {
            return {dic[target-nums[i]], i};
        } else {
            dic[nums[i]] = i;
        }
    }

    return {};
}

void test() {
    vector<int> nums;
    int target;
    nums = {2,7,11,15};
    target = 9;
    vector<int> ret;

    ret = twoSum(nums, target);
    for (int num : ret) {
        cout << num << " ";
    }
    cout << endl;


    nums = {3,2,4};
    target = 6;
    ret = twoSum(nums, target);
    for (int num : ret) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}
