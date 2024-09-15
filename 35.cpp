#include <iostream>
#include <vector>

using namespace std;

/*
存在目标值
不存在目标值
*/
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return left;
}

int main() {
    vector<int> nums;
    int target;
    int ret;

    nums = {1, 3, 5, 6};
    // target = 5;
    target = 2;
    ret = searchInsert(nums, target);
    cout << "ret:" << ret << endl;

    return 0;
}
