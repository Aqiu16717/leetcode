#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    
    // 创建一个DP数组用于存储到达每一阶楼梯的最小花费
    std::vector<int> dp(n + 1);
    
    // 开始动态规划
    for (int i = 2; i <= n; ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    
    return dp[n];
}

int main() {
    std::vector<int> cost = {10, 15, 20}; // 你可以修改这个数组来测试不同的花费情况
    int minCost = minCostClimbingStairs(cost);
    std::cout << "Minimum cost to climb stairs: " << minCost << std::endl;

    return 0;
}
