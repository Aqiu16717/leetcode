/**
 * 5. Longest Palindromic Substring
 * Given a string s, return the longest 
 * palindromic substring in s.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * dynamic programming
 *
 * state defination
 *   dp[i][j] indicates whether the substring from index i to j is a palindrome.
 *
 * initialization
 *   every single character is a palindrome so dp[i][i] is true.
 *   if two characters(i and i + 1) are the same then d[i][j](j = i + 1) is
 * true.
 *
 * state transition
 *   dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]
 *
 * loop sequence
 *   i relies on i + 1
 *   j relies on j - 1
 *
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int n = s.size();
        int start = 0;
        int maxlen = 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                if (dp[i][j]) {
                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        start = i;
                        cout << "(i,j):" << i << " " << j << endl;
                        cout << "start:" << start << endl;
                        cout << "maxlen:" << maxlen << endl;
                    }
                }
            }
        }

        cout << "start:" << start << endl;
        cout << "maxlen:" << maxlen << endl;
        return s.substr(start, maxlen);
    }
};

void test() {
    Solution solution;
    string str = "aaaa";

    string ret = solution.longestPalindrome(str);
    cout << ret << endl;
}

int main() {
    test();
    return 0;
}
