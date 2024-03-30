#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * [ref]
 * https://leetcode.cn/problems/integer-break/solutions/352875/zheng-shu-chai-fen-by-leetcode-solution
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            int curMax = 0;
            for (int j = 1; j < i; ++j) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int ret = s.integerBreak(10);
    assert(ret == 36);
    return 0;
}