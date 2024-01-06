#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        cnt = 0;
        return dfs(0, 0, s, t, 0);
    }

private:
    int dfs(int i, int j, string s, string t, int depth) {
        for (int i = 0; i < depth; i++) {
            cout << "\t";
        }
        cout << i << " " << j << endl;

        #if 0
        // optimize
        // remain len of s < remain len of t
        if (s.size() - i < t.size() - j) {
            return 0;
        }
        #endif

        // t reaches end
        if (j == t.size()) {
            return 1;
        }
        // t doesn't reach end and s reach end
        if (i == s.size()) {
            return 0;
        }

        if (cache.count({i, j})) {
            // cout << "cache found:" << i << " " << j << endl;
            return cache[{i, j}];
        }

        ++cnt;
        if (s[i] == t[j]) {
            cache[{i, j}] = dfs(i + 1, j + 1, s, t, cnt) + dfs(i + 1, j, s, t, cnt);
        } else {
            cache[{i, j}] = dfs(i + 1, j, s, t, cnt);
        }
        --cnt;
        return cache[{i, j}];
    }

private:
    map<pair<int, int>, int> cache;
    int cnt;
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ret = s.numDistinct("rabbbit", "rabbit");
    cout << "ret:" << ret << endl;
    return 0;
}
