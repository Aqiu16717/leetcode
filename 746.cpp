#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    if (n < 2) {
        return 0;
    }
    
    std::vector<int> dp(n + 1);
    
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    
    return dp[n];
}
/**
 * 
 * 0  1   2 3 4 5   6 7 8   9
 * 1, 100,1,1,1,100,1,1,100,1
 * 0  0   1 2 2 3   3 4 4   5 6
*/

// Optimize Space Complexity
int minCostClimbingStairsV2(vector<int>& cost) {
    int n = cost.size();
    if (n < 2) {
        return 0;
    }
    std::vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[2] = std::min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}


int main() {
    // std::vector<int> cost = {10, 15, 20};
    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int minCost = minCostClimbingStairs(cost);
    std::cout << "Minimum cost to climb stairs: " << minCost << std::endl;
    assert(minCost == 6);
    int minCost2 = minCostClimbingStairsV2(cost);
    assert(minCost == 6);
    std::cout << "Minimum cost to climb stairs: " << minCost2 << std::endl;

    return 0;
}
