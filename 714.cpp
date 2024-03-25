#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }

        return dp[n - 1][0];
    }

    // Optimize space complexity
    int maxProfitV2(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        vector<int> dp(2);

        dp[0] = 0;
        dp[1] = -prices[0] - fee;

        for (int i = 1; i < n; ++i) {
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], dp[0] - prices[i] - fee);
        }

        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    int ret = s.maxProfit(prices, fee);
    std::cout << "expect ret: 8." << std::endl;
    std::cout << "ret:" << ret << std::endl;
    int ret2 = s.maxProfitV2(prices, fee);
    std::cout << "expect ret2: 8." << std::endl;
    std::cout << "ret2: " << ret2 << std::endl;
    return 0;
}