#include <vector>
#include "common.h"

using namespace std;
/*
pre[i] = nums[0]*nums[1]*...*nums[i-1]
pre[i] = pre[i-1] * nums[i-1]
pre[0] = 1

suf[i] = nums[i+1]*nums[i+2]*...*nums[n-1]
suf[i] = suf[i+1] * nums[i+1]
suf[n-1] = 1

answer[i] = pre[i] * suf[i]
time complexity: O(n)
space complexity: O(n)

optimize space complexity to O(1)
optimize pre from array to a integer
use suf as result set
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int pre = 1;
    vector<int> suf(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        suf[i] = pre * suf[i];
        pre *= nums[i];
    }
    return suf;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> ret = productExceptSelf(nums);
    printVec(ret);
    return 0;
}
