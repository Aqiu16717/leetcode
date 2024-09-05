/*
15. 3Sum
Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
time: O(n^2)
space: O(1)
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] > 0) {
            break;
        }

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                // while (nums[right] == nums[right - 1]) {
                //     --right;
                // }
                --right;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                // while (nums[left] == nums[left + 1]) {
                //     ++left;
                // }
                ++left;
            } else {
                ret.push_back({nums[i], nums[left], nums[right]});
                while (nums[right] == nums[right - 1]) {
                    --right;
                }
                --right;
                while (nums[left] == nums[left + 1]) {
                    ++left;
                }
                ++left;
            }
        }
    }

    return ret;
}

void printVec(const vector<vector<int>>& vec) {
    for (const vector<int>& v : vec) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void test() {
    vector<int> nums;
    nums = {-1,0,1,2,-1,-4};
    // -4,-1,-1,0,1,2
    vector<vector<int>> ret;
    ret = threeSum(nums);
    printVec(ret);
}

int main()
{
    test();
    return 0;
}
