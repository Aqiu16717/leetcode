#include <iostream>
#include <vector>

#include "common.h"

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    int up = 0;
    int down = n - 1;
    while (up < down) {
        swap(matrix[up], matrix[down]);
        ++up;
        --down;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix;

    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "before:" << endl;
    print2DVec(matrix);
    rotate(matrix);
    cout << "after:" << endl;
    print2DVec(matrix);

    return 0;
}

/*
1,2,3
4,5,6
7,8,9


7,8,9
4,5,6
1,2,3

7,4,1
8,5,2
9,6,3
*/
