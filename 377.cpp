#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int combinationSum4_V0(vector<int>& nums, int target) {
    function<int(int)> dfs = [&](int sum)->int {
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }
        int ret = 0;
        for (int num : nums) {
            ret += dfs(sum + num);
        }
        return ret;
    };

    int sum = 0;
    return dfs(sum);
}

int combinationSum4_V1(vector<int>& nums, int target) {
    function<int(int)> dfs = [&](int sum)->int {
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }
        int ret = 0;
        for (int num : nums) {
            ret += dfs(sum + num);
        }
        return ret;
    };

    int sum = 0;
    return dfs(sum);
}

int combinationSum4_V2(vector<int>& nums, int target) {
    function<int(int)> dfs = [&](int sum)->int {
        if (sum > target) {
        return 0;
        }
        if (sum == target) {
            return 1;
        }
        int ret = 0;
        for (int num : nums) {
            ret += dfs(sum + num);
        }
        return ret;
    };

    int sum = 0;
    return dfs(sum);
}

int combinationSum4_V3(vector<int>& nums, int target) {
    function<int(int)> dfs = [&](int sum)->int {
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }
        int ret = 0;
        for (int num : nums) {
            ret += dfs(sum + num);
        }
        return ret;
    };

    int sum = 0;
    return dfs(sum);  
}

int combinationSum4_V4(vector<int>& nums, int target) {
    function<int(int)> dfs = [&](int sum)->int {
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }
        int ret = 0;
        for (int num : nums) {
            ret += dfs(sum + num);
        }
        return ret;
    };

    int sum = 0;
    return dfs(sum);
}


int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    cout << "V0 Test Case 1: " << combinationSum4_V0(nums1, target1) << " (Expected Output: 7)" << endl;
    cout << "V1 Test Case 1: " << combinationSum4_V1(nums1, target1) << " (Expected Output: 7)" << endl;
    cout << "V2 Test Case 1: " << combinationSum4_V2(nums1, target1) << " (Expected Output: 7)" << endl;
    cout << "V3 Test Case 1: " << combinationSum4_V3(nums1, target1) << " (Expected Output: 7)" << endl;
    cout << "V4 Test Case 1: " << combinationSum4_V4(nums1, target1) << " (Expected Output: 7)" << endl;
    return 0;
}
