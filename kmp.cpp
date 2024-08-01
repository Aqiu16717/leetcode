#include <vector>
#include <iostream>

using namespace std;

// 计算前缀函数的朴素算法
// 注：string substr (size_t pos = 0, size_t len = npos) const;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            // i是下标，j是长度，pi[i]是长度
            if (s.substr(0, j) == s.substr(i - j + 1, j)) {
                pi[i] = j;
                break;
            }
        }
    }
    return pi;
}


int main()
{
    return 0;
}