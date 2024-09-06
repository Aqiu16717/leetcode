#include <vector>
#include <iostream>

#include "common.h"

using namespace std;

void moveZeroes(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    int n = nums.size();
    while (fast < n) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            ++slow;
        }
        ++fast;
    }
}


void test() {
    vector<int> nums = {0,1,0,3,12};
    printVec(nums);
    moveZeroes(nums);
    printVec(nums);
}

int main()
{
    test();
}
