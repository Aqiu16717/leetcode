#include <iostream>
#include <vector>
#include <cassert>

/**
 * ref:https://leetcode.cn/problems/unique-binary-search-trees/solutions/329807/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution
 * 
*/

int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

int main() {
    int n = 3;
    int count = numTrees(n);
    std::cout << count << std::endl;
    assert(count == 5);

    return 0;
}
