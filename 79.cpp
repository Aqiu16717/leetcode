/*
we have 4 choices each time, up or down or left or right.
return false if current character doesn't match.
return true if one path matches the word.
we have to know the current index of the word.
we have to know the position in the board.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(const vector<vector<char>>& board, int x, int y, string word,
             int index, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }
        if (!isValid(board, x, y) || visited[x][y]) {
            return false;
        }
        if (board[x][y] != word[index]) {
            return false;
        }

        visited[x][y] = true;

        bool found = dfs(board, x - 1, y, word, index + 1, visited)
                || dfs(board, x + 1, y, word, index + 1, visited)
                || dfs(board, x, y - 1, word, index + 1, visited)
                || dfs(board, x, y + 1, word, index + 1, visited);

        visited[x][y] = false;

        return found;
    }

    bool isValid(const vector<vector<char>>& board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
};

void test() {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCB";
    bool ret = s.exist(board, word);
    cout << ret << endl;
}

int main()
{
    test();
    return 0;
}