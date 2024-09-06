#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    int left = 0;
    int right = 1;
    int max_len = 1;
    int n = s.size();
    while (right < n) {
        if (s[right] == s[right - 1]) {
            max_len = max(max_len, right - left);
            left = right;
        }
    }
    return max_len;
}

void test() {
    string s = "abcabcbb";
    int ret;
    ret = lengthOfLongestSubstring(s);
    cout << ret << endl;
}

int main()
{
    test();
    return 0;
}
