#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;

        // 0x0 brute force
        // time O(n^3)
        // space O(1)
        #if 0
        for (int right = 0; right < n; ++right) {
            for (int left = 0; left <= right; ++left) {
                if (isPalindromic(s, left, right)) {
                    ++ret;
                }
            }
        }
        #endif
        // 0x1 brute force
        // time O(n^3)
        // space O(1)
        #if 0
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindromic(s, i, j)) {
                    ++ret;
                }
            }
        }
        #endif

        // 0x2 dp 
        // time O(n^2)
        // space O(n^2)
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        ++ret;
                        dp[i][j] = true;
                    } else {
                        if (dp[i + 1][j - 1]) {
                            ++ret;
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }

        return ret;
    }
private:
    bool isPalindromic(const string& s, int left, int right) {
        while (left <= right) {
            if (s[left++] == s[right--]) {
                continue;
            }
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int ret = s.countSubstrings("abc");
    cout << ret << endl;
    return 0;
}
