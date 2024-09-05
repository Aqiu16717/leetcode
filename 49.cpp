/*
49. Group Anagrams
Given an array of strings strs, group the 
anagrams together. You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
time: O(nklogk), k is the length of the word.
space: O(n*k)
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> dic;
    for (string str : strs) {
        string tmp = str;
        sort(str.begin(), str.end());
        dic[str].push_back(tmp);
    }
    vector<vector<string>> ret;
    for (auto elem : dic) {
        ret.push_back(elem.second);
    }
    return ret;
}

template <typename T>
void printVecVec(const vector<vector<T>>& vec) {
    for (const auto& v : vec) {
        for (const auto& elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void test() {
    vector<string> strs;
    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = groupAnagrams(strs);
    printVecVec(ret);
}

int main()
{
    test();
    return 0;
}
