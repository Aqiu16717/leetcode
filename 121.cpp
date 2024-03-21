#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 保证只有一次买入
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            // dp[i][1] = max(dp[i - 1][1], dp[0][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};



// 空间压缩
class SolutionV2 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            dp[0] = max(dp[0], dp[1] + prices[i]);
            // 保证只有一次买入
            dp[1] = max(dp[1], -prices[i]);
        }
        return dp[0];
    }
};


int main(int argc, char const *argv[])
{
    vector<int> vec = {7, 1, 5, 3, 6, 4};
    Solution s;
    SolutionV2 s2;
    // int profit = s.maxProfit(vec);
    int profit = s2.maxProfit(vec);
    std::cout << profit << std::endl;
    return 0;
}
