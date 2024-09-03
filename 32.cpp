/**
 * 32. Longest Valid Parentheses
 * Given a string containing just the characters '(' and ')', return the length
 * of the longest valid (well-formed) parentheses substring.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * dynamic programming
 *
 * defination
 *   dp[i] indicates the longest legnth of valid parentheses substring that ends
 *   with s[i]
 *
 * initialization
 *
 * state transition
 *   if s[i] is ')'
 *     if s[i-1] is '(' then dp[i] = dp[i-2]+2.
 *       dp[i-2] is the longest length of valid substring before s[i] and
 * s[i-1]. +2 is the length of "()"
 *
 *     dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
 *
 *   if s[i] is '(' then dp[i] is 0.
 */

int longestValidParentheses(string s) {
    if (s.empty()) {
        return 0;
    }

    const int n = s.size();
    vector<int> dp(n, 0);
    int ret = 0;

    for (int i = 1; i < n; ++i) {
        if (s[i] == '(') {
            continue;
        }
        // s[i] == ')'
        if (s[i - 1] == '(') {
            dp[i] = (i >= 2 ? dp[i - 2] : 0)+ 2;
        } else {
            if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
                dp[i] = dp[i - 1] +
                        (i - dp[i - 1] - 2 >=0 ?
                          dp[i - dp[i - 1] - 2] :
                          0) + 2;
            }
        }
        ret = max(ret, dp[i]);
    }

    return ret;
}

void test() {
    string s;
    int ret;

    cout << "s:" << s << endl;
    ret = longestValidParentheses(s);
    cout << ret << endl;

    s = "(()";
    cout << "s:" << s << endl;
    ret = longestValidParentheses(s);
    cout << ret << endl;

    s = ")()())";
    cout << "s:" << s << endl;
    ret = longestValidParentheses(s);
    cout << ret << endl;
}
int main() {
    test();
    return 0;
}
