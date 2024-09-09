/**
 * 73. Set Matrix Zeroes
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row
 * and column to 0's.
 * You must do it in place.
 */

#include <vector>

#include "common.h"

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool first_row = false;
    bool first_col = false;

    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            first_col = true;
            break;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            first_row = true;
            break;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (first_row) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }

    if (first_col) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix;
    matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "befor: " << endl;
    print2DVec(matrix);
    setZeroes(matrix);
    cout << "after: " << endl;
    print2DVec(matrix);

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout << "befor: " << endl;
    print2DVec(matrix);
    setZeroes(matrix);
    cout << "after: " << endl;
    print2DVec(matrix);

    return 0;
}
