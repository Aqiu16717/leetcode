#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int left_max = 0;
    int right_max = 0;
    int total_water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > left_max) {
                left_max = height[left];
            } else {
                total_water += left_max - height[left];
            }
            ++left;
        } else {
            if (height[right] > right_max) {
                right_max = height[right];
            } else {
                total_water += right_max - height[right];
            }
            --right;
        }
    }
    return total_water;
}

void test() {
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ret;
    ret = trap(nums);
    cout << ret << endl;
}

int main() {
    test();
    return 0;
}
