#include <stdio.h>
#include <stdlib.h>

// [left, right]
// left close and right close
void merge(int* nums, int left, int mid, int right) {
    int* tmp = (int*)malloc((right - left + 1) * sizeof(int));

    int k = 0;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] < nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = nums[i++];
    }

    while (j <= right) {
        tmp[k++] = nums[j++];
    }

    for (int i = left; i <= right; ++i) {
        // notice: nums and tmp use different index
        nums[i] = tmp[i - left];
    }

    free(tmp);
}

void merge_sort(int* nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void print_array(int* arr, int arr_len) {
    for (int i = 0; i < arr_len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, arr_len);

    merge_sort(arr, 0, arr_len - 1);

    print_array(arr, arr_len);

    return 0;
}

