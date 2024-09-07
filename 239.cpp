#include <deque>
#include <iostream>
#include <vector>

#include "common.h"

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    int left = 0;
    int right = 0;
    deque<int> q;
    for (int i = 0; i < nums.size(); ++i) {
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() + 1 > k) {
            q.pop_front();
        }
        if ((i + 1) >= k) {
            ret.push_back(nums[q.front()]);
        }
    }

    return ret;
}

int main() {
    vector<int> nums;
    int k;
    vector<int> ret;
    nums = {1, 3, -1, -3, 5, 3, 6, 7};
    k = 3;
    ret = maxSlidingWindow(nums, k);
    printVec(ret);
    return 0;
}
