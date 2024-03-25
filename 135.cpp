#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

static void print_vec(vector<int>& vec) {
    for (auto& elem : vec) {
        cout << elem << "\t";
    }
    cout << endl;
}    


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> r(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                r[i] = r[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                r[i] = max(r[i], r[i + 1] + 1);
            }
        }
        return std::accumulate(r.begin(), r.end(), 0);
    }
};

class SolutionV2 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> r(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                r[i] = r[i + 1] + 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                r[i] = max(r[i], r[i - 1] + 1);
            }
        }
        return std::accumulate(r.begin(), r.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> ratings = {1, 2, 87, 87, 87, 2, 1};
    print_vec(ratings);
    int ret = s.candy(ratings);
    assert(ret == 13);
    SolutionV2 s2;
    ret = s2.candy(ratings);
    assert(ret == 13);
    return 0;
}