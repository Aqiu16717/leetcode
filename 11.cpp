#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int ret = 0;
    int cur_area = 0;
    while (left < right) {
        cur_area = min(height[left], height[right]) * (right - left);
        ret = max(ret, cur_area);
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return ret;
}

void test() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int ret;
    ret = maxArea(nums);
    cout << ret << endl;
}

int main() {
    test();
    return 0;
}
