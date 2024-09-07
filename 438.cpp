/**
 * 438. Find All Anagrams in a String
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different
 * word or phrase, typically using all the original letters exactly once.
 *
 */

// #include <iostream>
#include <vector>
#include <unordered_map>
#include "common.h"

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    int left = 0;
    int right = 0;
    unordered_map<char, int> dic;

    for (char c : p ) {
        dic[c]++;
    }

    while (right < s.size()) {
        if(dic[s[right]] > 0) {
            --dic[s[right]];
            ++right;
            // winsize:right - left
            if (right - left == p.size()) {
                ret.push_back(left);
                ++dic[s[left]];
                ++left;
            }
        } else {
            ++dic[s[left]];
            ++left;
        }
    }

    return ret;
}

void test() {
    vector<int> ret;
    string s;
    string p;

    s = "cbaebabacd";
    p = "abc";
    ret = findAnagrams(s, p);
    printVec(ret);

    s = "abab";
    p = "ab";
    ret = findAnagrams(s, p);
    printVec(ret);
}

int main() {
    test();
    return 0;
}
