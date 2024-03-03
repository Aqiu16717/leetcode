#include <vector>
#include <iostream>

using namespace std;

int combinationSum4_V0(vector<int>& nums, int target) {
    // 初始化dp数组，dp[i]表示和为i的组合个数
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;  // 初始情况，和为0的组合只有一个，即空集

    // 遍历目标整数的所有可能取值
    for (int i = 1; i <= target; ++i) {
        // 遍历数组nums中的每个元素
        for (int num : nums) {
            // 如果i >= num，表示当前目标整数i可以由num和之前的组合构成
            if (i >= num) {
                // 更新dp[i]，加上dp[i - num]
                dp[i] += dp[i - num];
            }
        }
    }

    // dp[target]就是和为target的组合个数
    return dp[target];
}

int combinationSum4_V1(vector<int>& nums, int target) {
    // 初始化二维dp数组，dp[i][j]表示和为j的组合个数
    vector<vector<unsigned int>> dp(nums.size() + 1, vector<unsigned int>(target + 1, 0));
    dp[0][0] = 1;  // 初始情况，和为0的组合只有一个，即空集

    // 遍历数组nums中的每个元素
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 0; j <= target; ++j) {
            // dp[i][j]等于不选择当前元素的组合个数
            dp[i][j] = dp[i - 1][j];
            
            // 如果j >= nums[i - 1]，表示当前目标整数j可以由nums[i - 1]和之前的组合构成
            if (j >= nums[i - 1]) {
                // 更新dp[i][j]，加上dp[i][j - nums[i - 1]]
                dp[i][j] += dp[i][j - nums[i - 1]];
            }
        }
    }

    std::cout << std::endl;
    for (auto& vec : dp) {
        for (auto elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // dp[nums.size()][target]就是和为target的组合个数
    return dp[nums.size()][target];
}

// wrong
int combinationSum4_V2(vector<int>& nums, int target) {
    // 初始化二维dp数组，dp[i][j]表示和为j的组合个数
    vector<vector<unsigned int>> dp(nums.size() + 1, vector<unsigned int>(target + 1, 0));
    dp[0][0] = 1;  // 初始情况，和为0的组合只有一个，即空集

    // 遍历数组nums中的每个元素
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 0; j <= target; ++j) {
            // dp[i][j]等于不选择当前元素的组合个数
            dp[i][j] = dp[i - 1][j];
            
            // 如果j >= nums[i - 1]，表示当前目标整数j可以由nums[i - 1]和之前的组合构成
            if (j >= nums[i - 1]) {
                // 更新dp[i][j]，加上dp[i][j - nums[i - 1]]
                dp[i][j] += dp[i][j - nums[i - 1]];
            }
        }
    }

    std::cout << std::endl;
    for (auto& vec : dp) {
        for (auto elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // dp[nums.size()][target]就是和为target的组合个数
    return dp[nums.size()][target];
}

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    cout << "V0 Test Case 1: " << combinationSum4_V0(nums1, target1) << " (Expected Output: 7)" << endl;
    cout << "V1 Test Case 1: " << combinationSum4_V1(nums1, target1) << " (Expected Output: 7)" << endl;
    cout << "V2 Test Case 1: " << combinationSum4_V2(nums1, target1) << " (Expected Output: 7)" << endl;
    return 0;
}
