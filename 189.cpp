#include <vector>
#include <algorithm>
#include "common.h"

using namespace std;

void rotate(vector<int>& nums, int k) {
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums, k);
    printVec(nums);
    return 0;
}
