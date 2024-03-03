#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int n = prices.size();
    // 定义状态数组
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));

    // 初始化状态
    for (int i = 0; i < 3; ++i) {
        dp[0][i][0] = 0;
        dp[0][i][1] = -prices[0];
    }

    // 遍历天数
    for (int i = 1; i < n; ++i) {
        // 遍历交易次数
        for (int j = 1; j < 3; ++j) {
            // 未持有股票
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
            // 持有股票
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "(";
            for (int k = 0; k < 2; ++k) {
                cout << dp[i][j][k] << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }

    return dp[n-1][2][0];
}

// 示例
int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int result = maxProfit(prices);
    cout << result << endl;  // 输出 6
    return 0;
}
