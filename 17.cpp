#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * two layers of loops correspond to two traversal of two targets.
 * record start position to prevent repeated visiting.
 *
 * time: O(n4^n)
 * space: O(n)
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> dic{"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        string path;
        dfs(digits, ret, dic, path, 0);
        return ret;
    }

private:
    void dfs(string digits, vector<string>& ret, vector<string>& dic,
             string& path, int begin) {
        if (path.size() == digits.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = begin; i < digits.size(); ++i) {
            for (char c : dic[digits[i] - '0']) {
                path.push_back(c);
                dfs(digits, ret, dic, path, i + 1);
                path.pop_back();
            }
        }
    }
};

/*
2    3
abc  def

a      b       c
def    def     def
*/

int main() {
    string digits;
    vector<string> ret;
    Solution s;

    digits = "23";
    ret = s.letterCombinations(digits);
    printVec(ret);

    return 0;
}
