#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        unordered_map<char, int> lastIdx;
        for (int i = 0; i < s.size(); ++i) {
            lastIdx[s[i]] = i;
        }
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastIdx[s[i]]);
            if (i == end) {
                ret.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ret;
    }
};
/**
ababcbaca defegde hijhklij
           i
          s      
                e
**/


int main()
{
    Solution s;
    string x = "ababcbacadefegdehijhklij";
    vector<int> ret = s.partitionLabels(x);
    cout << "expect:\t9 7 8" << endl;
    cout << "ret:\t";
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}