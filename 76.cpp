/**
 * 76. Minimum Window Substring
 * Given two strings s and t of lengths m and n respectively, return the minimum
 * window substring of s such that every character in t (including duplicates)
 * is included in the window. If there is no such substring, return the empty
 * string
 * "".
 *
 * The testcases will be generated such that the answer is unique.
 */
#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;

/**
 * use two hashtable
 *   'need' records every character frequency in t.
 *   'window' records every character frequency in current window.
 * sliding window
 *   left=0
 *   right=0
 *   * expand the window
 *   * shring the window
 */
string minWindow(string s, string t) {
    unordered_map<char, int> need;
    unordered_map<char, int> window;

    for (char c : t) {
        need[c]++;
    }

    int left = 0, right = 0;
    int formed = 0, required = need.size();
    int min_start = 0;
    int min_len = INT_MAX;

    while (right < s.size()) {
        window[s[right]]++;
        if (need.count(s[right]) && window[s[right]] == need[s[right]]) {
            // cout << "formed:" << formed << endl;
            ++formed;
        }
        ++right;

        while (formed == required) {
            // cout << "required:" << required << endl;
            // cout << "fuck" << endl;
            // cout << "left:" << left << endl;
            // cout << "right:" << right << endl;
            if (right - left < min_len) {
                min_start = left;
                min_len = right - left;
            }
            window[s[left]]--;
            if (window[s[left]] < need[s[left]]) {
                --formed;
            }
            ++left;
        }
    }

    return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
}

int main() {
    string s;
    string t;
    string ret;

#if 1
    s = "ADOBECODEBANC";
    t = "ABC";
    ret = minWindow(s, t);
    cout << ret << endl;

    s = "A";
    t = "A";
    ret = minWindow(s, t);
    cout << ret << endl;

    s = "A";
    t = "AA";
    ret = minWindow(s, t);
    cout << ret << endl;
#endif

    s = "ab";
    t = "a";
    ret = minWindow(s, t);
    cout << ret << endl;

    return 0;
}
