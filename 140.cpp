#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> path;
        dfs(s, 0, path, wordDict);
        return ret;
    }
private:
    void dfs(string s, int left, vector<string>& path, vector<string>& wordDict) {
        if (left == s.size()) {
            string sen;
            for (int i = 0; i < path.size() - 1; ++i) {
                sen += path[i] + " ";
            }
            sen += path[path.size() - 1];
            ret.push_back(sen);
            return;
        }
        if (left > s.size()) {
            return;
        }
        for (const string& word : wordDict) {
            if (s.substr(left, word.size()) != word) {
                continue;
            }
            path.push_back(word);
            dfs(s, left + word.size(), path, wordDict);
            path.pop_back();
        }
    }
private:
    vector<string> ret;
};

int main()
{
    Solution so;
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    vector<string> ret = so.wordBreak(s, wordDict);
    for (auto str : ret) {
        cout << str << endl;
    }
    return 0;
}
