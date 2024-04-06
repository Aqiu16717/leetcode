#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// dfs + memo
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size() + 1, -1);
        return dfs(s, 0, wordDict);
    }

private:
    bool dfs(string s, int left, vector<string>& wordDict) {
        if (left == s.size()) {
            return true;
        }
        bool ret = false;
        if (memo[left] != -1) {
            ret = memo[left] == 1 ? true : false;
            return ret;
        }
        for (const string& w : wordDict) {
            if (s.substr(left, w.size()) != w) {
                continue;
            }
            ret = ret || dfs(s, left + w.size(), wordDict);
            if (ret == true) {
                memo[left] = 1;
                return true;
            }
        }
        memo[left] = 0;
        return ret;
    }
private:
    vector<int> memo;
};


// dp
class SolutionV2 {
public:
    // bottom up
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (const string& w : wordDict) {
                if (i >= w.size() && s.substr(i - w.size(), w.size()) == w) {
                    dp[i] = dp[i] || dp[i - w.size()];
                    // no break here.
                    // 不能保证只有一个单词符合条件进入到这里
                    // dp[i] 会被计算多次
                    // break;
                }
            }
        }
        return dp[s.size()];
    }
};

/*

cur: l
wordDict: leet code

cur: le
wordDict: leet code

...

cur: leet
wordDict: leet code

*/


int main()
{
    {
        Solution s;
        string word = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        bool ret = s.wordBreak(word, wordDict);
        assert(ret == true);
    }
    {
        SolutionV2 s;
        string word = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        bool ret = s.wordBreak(word, wordDict);
        assert(ret == true);
    }
    return 0;
}