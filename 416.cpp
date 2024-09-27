#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T1, typename T2>
void printMap(const std::unordered_map<T1, T2>& m) {
    for (auto kv : m) {
        std::cout << "(" << kv.first << "," << kv.second << ")";
    }
    std::cout << std::endl;
}

#if 0
class Solution {
public:
    // bool<--->make judgement
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum % 2) {
            return false;
        }
        vector<bool> visited(n, false);
        // lower the time usage
        unordered_map<int, bool> memo;
        // *debug*
        bool ret = dfs(nums, sum / 2, visited, memo);
        //printMap(memo);
        return ret;
    }

    bool dfs(vector<int>& nums, int half_sum, vector<bool>& visited,
             unordered_map<int, bool>& memo) {
        if (half_sum == 0) {
            return true;
        }
        if (memo.count(half_sum)) {
            return memo[half_sum];
        }
        // how to return the result
        // as long as there is one path works, then the result can be returned
        bool ret = false;
        for (int i = 0; i < nums.size(); ++i) {
            // choose any one except self, so we need visited array
            if (visited[i] || nums[i] > half_sum) {
                continue;
            }
            visited[i] = true;
            ret = ret || dfs(nums, half_sum - nums[i], visited, memo);
            visited[i] = false;
            if (ret) {
                break;
            }
        }
        memo[half_sum] = ret;
        return ret;
    }
};
#endif

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

void testPrintMap() {
    unordered_map<int, bool> m;
    m[1] = true;
    m[2] = false;
    printMap(m);
}

int main() {
    // testPrintMap();
#if 1
    Solution s;
    bool ret;
    vector<int> nums;

    // nums = {1, 4, 5, 8, 12, 13, 14, 17, 18};
    nums = {1, 5, 11, 5};
    ret = s.canPartition(nums);
    cout << "ret:" << ret << endl;
#endif

    return 0;
}
