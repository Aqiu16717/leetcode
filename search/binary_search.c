#include <stdio.h>

int binary_search(int* arr, int target, int low, int high) {
    if (low > high ) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binary_search(arr, target, low, mid - 1);
    } else {
        return binary_search(arr, target, mid + 1, high);
    }
    return -1;
}

int binary_search_v2(int* arr, int target, int low, int high) {
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void test_binary_search() {
    int arr[10] = {1,3,5,7,8,9,10,11,12,13};
    int ret = binary_search(arr, 5, 0, 9);
    printf("ret:%d\n", ret);
    ret = binary_search(arr, 14, 0, 9);
    printf("ret:%d\n", ret);
}

void test_binary_search_v2() {
    int arr[10] = {1,3,5,7,8,9,10,11,12,13};
    int ret = binary_search(arr, 5, 0, 9);
    printf("ret:%d\n", ret);
    ret = binary_search(arr, 14, 0, 9);
    printf("ret:%d\n", ret);
}

int main()
{
    // test_binary_search();
    test_binary_search_v2();
    return 0;
}
