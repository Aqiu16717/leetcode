#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// dfs + cache
class Solution {
public:
    int numSquares(int n) {
        cache = vector<int>(n + 1, -2);
        return dfs(n);
    }
private:
    int dfs(int n) {
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            return 0;
        }
        if (cache[n] != -2) {
            return cache[n];
        }
        int ret = n + 1;
        int y;
        for (int i = 1; i*i <= n; ++i) {
            y = dfs(n - i * i);
            if (y == -1) {
                continue;
            }
            ret = min(ret, y + 1);
        }
        cache[n] = ret;
        return ret;
    }
private:
    vector<int> cache;
};
/*
dfs(12)
        [...,3,...]
    dfs(8)
            [...,2,...]
        dfs(4)
               [2,1] 
            dfs(1)   dfs(0)
             [1]     [0]
*/

// dp
// bottom up
class SolutionV2 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (i - j * j >= 0) {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    {
        Solution s;
        int ret = s.numSquares(12);
        assert(ret == 3);
    }
    {
        SolutionV2 s;
        int ret = s.numSquares(12);
        assert(ret == 3);
    }
    return 0;
}