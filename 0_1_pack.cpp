#include <iostream>
#include <vector>

int knapsack2D(int W, std::vector<int> weight, std::vector<int> value) {
    int n = weight.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }

    for (std::vector<int>& v : dp) {
        for (int e : v) {
            std::cout << e << " ";
        }
        std::cout << '\n';
    }

    return dp[n][W];
}

int knapsack1D(int W, std::vector<int> weight, std::vector<int> value) {
    int n = weight.size();
    std::vector<int> dp(W + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = W; j >= weight[i - 1]; --j) {
        // for (int j = 1; j <= W; ++j) {
            dp[j] = std::max(dp[j], dp[j - weight[i - 1]] + value[i - 1]);
            std::cout << dp[j] << " ";
        }
        std::cout << '\n';
    }

    return dp[W];
}

int main() {
    std::vector<int> weight = {2, 3, 4, 5}; // 物品的重量
    std::vector<int> value = {3, 4, 5, 6};  // 物品的价值
    int W = 5; // 背包最大承重
    int max_value = knapsack2D(W, weight, value);
    std::cout << "2D:背包能获得的最大价值为: " << max_value << std::endl;
    std::cout << std::endl;
    max_value = knapsack1D(W, weight, value);
    std::cout << "1D:背包能获得的最大价值为: " << max_value << std::endl;

    return 0;
}
