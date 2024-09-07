#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void printVec(const vector<T>& vec) {
    std::cout << "[ ";
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

/*
time: O(n*logn)
space: O(n)
*/
#if 0
int longestConsecutive(vector<int>& nums) {
    set<int> dic(nums.begin(), nums.end());
    vector<int> tmp(dic.begin(), dic.end());
    // printVec(tmp);
    int ret = 0;
    int curLen = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        if (i > 0 && tmp[i] != tmp[i - 1] + 1) {
            ret = max(curLen, ret);
            curLen = 0;
        }
        ++curLen;
    }
    ret = max(curLen, ret);
    return ret;
}
#endif

int longestConsecutive(vector<int>& nums) {
    int ret = 0;

    unordered_set<int> dic(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        // find the start point
        if (!dic.count(nums[i] - 1)) {
            int j = 0;
            for (; dic.count(nums[i] + j); ++j) {
                // do nothing
            }
            ret = max(ret, j);
        }
    }

    return ret;
}

void test() {
    vector<int> nums;
    int ret;

    nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    printVec(nums);
    ret = longestConsecutive(nums);
    cout << ret << endl;
}

int main() {
    test();
    return 0;
}
