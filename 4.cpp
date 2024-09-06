#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    double ret;
    return ret;
}

void test() {
    vector<int> nums1;
    vector<int> nums2;
    double ret;

    cout << "nums1:{1, 3}, nums2:{2}" << endl;
    nums1 = {1, 3};
    nums2 = {2};
    ret = findMedianSortedArrays(nums1, nums2);
    cout << "ret:" << ret << endl;

    cout << "nums1:{1, 2}, nums2:{3, 4}" << endl;
    nums1 = {1, 2};
    nums2 = {3, 4};
    ret = findMedianSortedArrays(nums1, nums2);
    cout << "ret:" << ret << endl;
}

int main()
{
    test();
    return 0;
}
