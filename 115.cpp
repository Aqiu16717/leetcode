#include <iostream>
#include <map>
#include <vector>

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

class SolutionV2 {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> cache(s.size() + 1, vector<int>(t.size() + 1, -1));
        int ret = dfs(s, t, 0, 0, cache);
        // for (auto elem : cache) {
        //     cout << elem.first << "\t" << elem.second << endl;
        // }
        return ret;
    }

private:
    int dfs(const string& s, const string& t, int sIndex, int tIndex, vector<vector<int>>& cache) {
        if (cache[sIndex][tIndex] != -1) {
            return cache[sIndex][tIndex];
        }

        if (tIndex == t.length()) {
            return 1;
        }
        
        if (sIndex == s.length()) {
            return 0;
        }
        
        int count = 0;
        
        if (s[sIndex] == t[tIndex]) {
            count += dfs(s, t, sIndex + 1, tIndex + 1, cache);
        }
        
        count += dfs(s, t, sIndex + 1, tIndex, cache);
        
        // Cache the result
        cache[sIndex][tIndex] = count;
        cout << sIndex << "\t" << tIndex << "\t" << count << endl;
           return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ret = s.numDistinct("rabbbit", "rabbit");
    cout << "ret:" << ret << endl;

    SolutionV2 s2;
    ret = s2.numDistinct("rabbbit", "rabbit");
    cout << "ret:" << ret << endl;
    return 0;
}
