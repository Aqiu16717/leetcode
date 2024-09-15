package main

import "fmt"

func searchMatrix(matrix [][]int, target int) bool {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return false
    }

    rows := len(matrix)
    cols := len(matrix[0])
    
    // Start at the top-right corner
    row := 0
    col := cols - 1
    
    // Traverse the matrix
    for row < rows && col >= 0 {
        if matrix[row][col] == target {
            return true
        } else if matrix[row][col] > target {
            col-- // Move left
        } else {
            row++ // Move down
        }
    }

    return false
}

func main() {
    // Test cases
    testCases := []struct {
        matrix [][]int
        target int
        want   bool
    }{
        {
            matrix: [][]int{
                {1, 4, 7, 11, 15},
                {2, 5, 8, 12, 19},
                {3, 6, 9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30},
            },
            target: 5,
            want:   true,
        },
        {
            matrix: [][]int{
                {1, 4, 7, 11, 15},
                {2, 5, 8, 12, 19},
                {3, 6, 9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30},
            },
            target: 20,
            want:   false,
        },
        {
            matrix: [][]int{
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20},
                {21, 22, 23, 24, 25},
            },
            target: 13,
            want:   true,
        },
        {
            matrix: [][]int{
                {1, 4},
                {2, 5},
            },
            target: 6,
            want:   false,
        },
    }

    for _, tc := range testCases {
        got := searchMatrix(tc.matrix, tc.target)
        if got == tc.want {
            fmt.Printf("Test passed for target %d\n", tc.target)
        } else {
            fmt.Printf("Test failed for target %d, got %v, want %v\n", tc.target, got, tc.want)
        }
    }
}
