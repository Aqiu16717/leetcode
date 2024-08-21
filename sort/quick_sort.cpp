#include <iostream>
#include <vector>

int partition(std::vector<int>& nums, int left, int right) {
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            --j;
        }
        while (i < j && nums[i] <= nums[left]) {
            ++i;
        }
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[left]);
    return i;
}

void quick_sort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quick_sort(nums, left, pivot-1);
    quick_sort(nums, pivot + 1, right);
}

void printVec(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {10, 7, 8, 9, 1, 5};
    printVec(vec);
    quick_sort(vec, 0, vec.size() - 1);
    printVec(vec);
    return 0;
}