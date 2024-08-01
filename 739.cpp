/**
 * https://leetcode.cn/problems/daily-temperatures/
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                ret[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ret = s.dailyTemperatures(temperatures);
    // expect: 1,1,4,2,1,1,0,0
    for (int elem : ret) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}