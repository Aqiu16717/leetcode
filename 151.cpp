#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverString(s, 0, s.size() - 1);

        int slow = 0;
        int fast = 0;
        // remove extra spaces and add one space after each word.
        for ( ; fast < s.size(); ) {
            if (s[fast] == ' ') {
                ++fast;
                continue;
            }
            if (slow != 0) {
                s[slow++] = ' ';
            }

            int begin = slow;
            while (fast < s.size() && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
            reverString(s, begin, slow - 1);
        }
        return s.substr(0, slow); 
    }
private:
    void reverString(string& s, int left, int right) {
        while (left < right) {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};

int main()
{
    Solution s;
    std::string ret;

    ret = s.reverseWords("the sky is blue");
    std::cout << ret << std::endl;

    ret = s.reverseWords("  hello world  ");
    std::cout << ret << std::endl;

    return 0;
}