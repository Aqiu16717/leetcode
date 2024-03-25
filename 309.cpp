#include <iostream>
#include <vector>

using namespace std;


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) {
        return 0;
    }

    // Define status
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Init status
    dp[0][0] = -prices[0]; // Hold stock
    dp[0][1] = 0; // Do not hold stock and are in freezing period
    dp[0][2] = 0; // Do not hold stock and aret not in freezing period

    // Iterate days
    for (int i = 1; i < n; ++i) {
        // State transition
        dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
        dp[i][1] = dp[i-1][0] + prices[i];
        dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
    }

    // The final result is the maximum profit without holding the stock.
    // Taking into account the freezing period.
    return max(dp[n - 1][1], dp[n - 1][2]);
}

// Optimize the space complexity.
int maxProfitV2(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) {
        return 0;
    }

    vector<int> dp(3, 0);
    dp[0] = -prices[0];
    dp[1] = 0;
    dp[2] = 0;

    for (int i = 1; i < n; ++i) {
        int prev0 = dp[0];
        int prev1 = dp[1];
        int prev2 = dp[2];
        dp[0] = max(dp[0], dp[2] - prices[i]);
        dp[1] = prev0 + prices[i];
        dp[2] = max(prev1, dp[2]);
    }

    return max(dp[1], dp[2]);
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    int result = maxProfit(prices);
    cout << result << endl;  // Expect 3
    vector<int> prices2 = {1, 2, 3, 0, 2};
    int result2 = maxProfitV2(prices2);
    cout << result2 << endl;  // Expect 3
    return 0;
}