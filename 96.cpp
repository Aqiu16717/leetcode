#include <iostream>
#include <vector>

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
    int n = 3; // 可以根据需要修改节点数量 n
    int count = numTrees(n);
    std::cout << "不同的二叉搜索树数量为: " << count << std::endl;

    return 0;
}
