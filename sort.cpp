#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

static void EXPECT_VECTOR_EQ(const std::vector<int>& v1,
                             const std::vector<int>& v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < v1.size(); ++i) {
        assert(v1[i] == v2[i]);
    }
    std::cout << "PASSED" << std::endl;
}

class Sort {
public:
    void bubble_sort(std::vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for (int i = n - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    flag = true;
                    std::swap(nums[j], nums[j + 1]);
                }
            }
            if (!flag) {
                break;
            }
        }
    }

    void selection_sort(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] < nums[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(nums[i], nums[min_idx]);
        }
    }

    void insertion_sort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int tmp = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > tmp) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = tmp;
        }
    }
    /**
     * 27, 85, 12, 43, 68, 91, 34, 57, 6, 74
     * i                                   j
     * p
     *                                 j  
     *     i 
     * 27, 6, 12, 43, 68, 91, 34, 57, 85, 74
     *         j
     *         i
     */

    void quick_sort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int i = low;
            int j = high;
            int pivot = nums[low];
            while (i < j) {
                while (i < j && nums[j] >= pivot) {
                    --j;
                }
                while (i < j && nums[i] <= pivot) {
                    ++i;
                }
                std::swap(nums[i], nums[j]);
            } 
            nums[i] = pivot;
            quick_sort(nums, low, i - 1);
            quick_sort(nums, i + 1, high);
        }
    }

    void merge_sort(std::vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
        std::vector<int> tmp(right - left + 1);
    }
    void merge(std::vector<int> &nums, int left, int mid, int right) {
    }
};

static void printVec(const std::vector<int>& vec) {
    for (auto elem : vec) {
        std::cout << elem << "\t";
    }
    std::cout << "\n";
}

void test_bubble_sort() {
    std::cout << __func__ << std::endl;
    Sort s;
    std::vector<int> nums = {27, 85, 12, 43, 68, 91, 34, 57, 6, 74};
    // std::cout << "before" << std::endl;
    // printVec(nums);
    s.bubble_sort(nums);
    // std::cout << "after" << std::endl;
    // printVec(nums);
    EXPECT_VECTOR_EQ(nums, {6, 12, 27, 34, 43, 57, 68, 74, 85, 91});
}

void test_selection_sort() {
    std::cout << __func__ << std::endl;
    Sort s;
    std::vector<int> nums = {27, 85, 12, 43, 68, 91, 34, 57, 6, 74};
    // std::cout << "before" << std::endl;
    // printVec(nums);
    s.selection_sort(nums);
    // std::cout << "after" << std::endl;
    EXPECT_VECTOR_EQ(nums, {6, 12, 27, 34, 43, 57, 68, 74, 85, 91});
    // printVec(nums);
}

void test_insertion_sort() {
    std::cout << __func__ << std::endl;
    Sort s;
    std::vector<int> nums = {27, 85, 12, 43, 68, 91, 34, 57, 6, 74};
    s.insertion_sort(nums);
    EXPECT_VECTOR_EQ(nums, {6, 12, 27, 34, 43, 57, 68, 74, 85, 91});
}

void test_quick_sort() {
    std::cout << __func__ << std::endl;
    Sort s;
    std::vector<int> nums = {27, 85, 12, 43, 68, 91, 34, 57, 6, 74};
    s.quick_sort(nums, 0, nums.size() - 1);
    EXPECT_VECTOR_EQ(nums, {6, 12, 27, 34, 43, 57, 68, 74, 85, 91});
}

void run_test() {
    test_bubble_sort();
    test_selection_sort();
    test_insertion_sort();
    test_quick_sort();
}

int main() {
    run_test();
    return 0;
}