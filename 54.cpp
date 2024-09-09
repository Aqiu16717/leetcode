/**
 * 54. Spiral Matrix
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 */

#include <vector>

#include "common.h"

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;
    int count_target = m * n;

    int left = 0, right = n - 1;
    int up = 0, down = m - 1;

    while (count < count_target) {
        for (int i = left; i <= right; ++i) {
            ret.push_back(matrix[up][i]);
            ++count;
        }
        ++up;
        for (int i = up; i <= down; ++i) {
            ret.push_back(matrix[i][right]);
            ++count;
        }
        --right;
        for (int i = right; i >= left; --i) {
            ret.push_back(matrix[down][i]);
            ++count;
        }
        --down;
        for (int i = down; i >= up; --i) {
            ret.push_back(matrix[i][left]);
            ++count;
        }
        ++left;
    }
    ret.resize(count_target);

    return ret;
}

int main() {
    vector<vector<int>> matrix;
    vector<int> ret;

    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ret = spiralOrder(matrix);
    printVec(ret);

    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    ret = spiralOrder(matrix);
    printVec(ret);

    return 0;
}
