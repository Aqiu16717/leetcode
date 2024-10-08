#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        #if DEBUG
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
        #endif

        return dp[m - 1][n - 1];
    }
};

class SolutionV2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] = dp[j] + dp[j - 1];
                #if DEBUG
                cout << dp[j] << "\t";
                #endif
            }
            cout << endl;
        }


        return dp[n - 1];
    }
};

int main()
{
    Solution s; 
    
    // int ret = s.uniquePaths(3, 2);
    int ret = s.uniquePaths(3, 7);
    cout << "ret:" << ret << endl;

    SolutionV2 s2;
    int ret2 = s2.uniquePaths(3, 7);
    cout << "ret2:" << ret2 << endl;

    return 0;
}