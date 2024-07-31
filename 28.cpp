#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next = getNext(needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j]) {
                ++j;
            }

            if (j == needle.size()) {
                return i - j + 1;
            }
        }
        return -1;
    }
private:
    vector<int> getNext(const string& s) {
        vector<int> pi(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            int j = pi[i - 1]; 
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            pi[i] = j;
        }
        return pi;
    }
};

int main()
{
    Solution s;
    std::cout << s.strStr("ababe", "ab") << std::endl;;
    std::cout << s.strStr("ababe", "eb") << std::endl;;
}