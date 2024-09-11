#include <iostream>
#include <vector>

using namespace std;

/*
We have 2 choices everty time; Choose '(' or ')'.
We have to follow these rules.
  1. left parentheses less than or equal to n.
  2. right parentheses less than or equal to n.
  3. left parentheses more than or equal to right parentheses.
When to stop tracking?
  right parenthese equal to n
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        dfs(n, ret, path, 0, 0);
        return ret;
    }
    void dfs(int n, vector<string>& ret, string path, int open_cnt,
             int close_cnt) {
        if (open_cnt > n || close_cnt > n || close_cnt > open_cnt) {
            return;
        }
        if (close_cnt == n) {
            ret.push_back(path);
            return;
        }
        path.push_back('(');
        dfs(n, ret, path, open_cnt + 1, close_cnt);
        path.pop_back();
        path.push_back(')');
        dfs(n, ret, path, open_cnt, close_cnt + 1);
        path.pop_back();
    }
};

template <typename T>
void printVec(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution s;
    int n;
    vector<string> ret;

    n = 3;
    ret = s.generateParenthesis(n);
    printVec(ret);

    return 0;
}
