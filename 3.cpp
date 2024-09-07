#include <iostream>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    int left = 0;
    int right = 0;
    int max_len = 1;
    int n = s.size();
    unordered_set<int> dic;
    while (right < n) {
        if (dic.count(s[right])) {
            dic.erase(s[left]);
            ++left;
        } else {
            dic.insert(s[right]);
            ++right;
            max_len = max(max_len, right - left);
        }
    }
    return max_len;
}

void test() {
    string s = "abcabcbb";
    int ret;
    ret = lengthOfLongestSubstring(s);
    cout << ret << endl;

    s = "bbbbb";
    ret = lengthOfLongestSubstring(s);
    cout << ret << endl;

    s = "pwwkew";
    ret = lengthOfLongestSubstring(s);
    cout << ret << endl;
}

int main()
{
    test();
    return 0;
}
