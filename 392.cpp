#include <iostream>
#include <vector>

using namespace std;

#if 0
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        bool ret = true;
        int i = 0;
        int j = i;
        for ( ; i < n; ++i) {
            for ( ; j < m; ++j) {
                if (s[i] == t[j]) {
                    break;
                }
            }
            // current char in s was not found in t.
            if (j == m) {
                ret = false;
                break;
            }
            ++j;
        }

        return ret;
    }

    void test(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(m, vector<int>(26, 0));
        int nextPos;
        for (char c = 'a'; c <= 'z'; ++c) {
            nextPos = -1; 
            for (int i = m - 1; i >= 0; --i) {
                dp[i][c - 'a'] = nextPos;
                if (t[i] == c) {
                    nextPos = i;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 26; ++j) {
                cout << "\t" << dp[i][j];
            }
            cout << endl;
        }
    }
};
#endif

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int> > f(m + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            f[m][i] = m;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a')
                    f[i][j] = i;
                else
                    f[i][j] = f[i + 1][j];
            }
        }
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (f[add][s[i] - 'a'] == m) {
                return false;
            }
            add = f[add][s[i] - 'a'] + 1;
        }
        return true;
    }
};



int main(int argc, char const *argv[])
{
    Solution s;

    // s.isSubsequence("aaaaaa", "bbaaaa");
    s.isSubsequence("abc", "ahbgdc");
    // s.test("abc", "ahbgdc");

    return 0;
}
