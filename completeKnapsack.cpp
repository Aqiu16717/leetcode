#include <iostream>
#include <vector>

int complete_knapsack_v0(int W, std::vector<int>& weight, std::vector<int>& value) {
    int n = weight.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }

    for (auto& v : dp) {
        for (auto elem : v) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return dp[n][W];
}

int complete_knapsack_v1(int W, std::vector<int>& weight, std::vector<int>& value) {
    int n = weight.size();
    std::vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = weight[i]; j <= W; ++j) {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[W];
}

// 0-1 knapsack
int knapsack2D(int W, std::vector<int> weight, std::vector<int> value) {
    int n = weight.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
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

int main() {
    std::vector<int> weight = {2, 3, 4, 5};
    std::vector<int> value = {3, 4, 5, 6};
    int W = 8;

    std::cout << "complete knapsack:";
    int max_value = complete_knapsack_v0(W, weight, value);
    std::cout << "Maximum value that can be obtained: " << max_value << std::endl;

    std::cout << "0-1 knapsack:";
    max_value = knapsack2D(W, weight, value);
    std::cout << "Maximum value that can be obtained: " << max_value << std::endl;

    return 0;
}
