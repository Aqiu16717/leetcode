#include <iostream>
#include <vector>

using namespace std;

// A subsequence of a string is a new string
// that is formed from the original string by
// deleting some (can be none) of the characters without
// disturbing the relative positions of the remaining characters

void dfs(const std::string &str, int idx, const std::string path,
         std::vector<std::string> &subsequences);

std::vector<std::string> getAllSubsequences(const std::string &str) {
    string path;
    vector<string> subsequences;
    dfs(str, 0, path, subsequences);
    return subsequences;
}
void dfs(const std::string &str, int idx, const std::string path,
         std::vector<std::string> &subsequences) {
    if (idx == str.length()) {
        subsequences.push_back(path);
        return;
    }
    dfs(str, idx + 1, path + str[idx], subsequences);
    dfs(str, idx + 1, path, subsequences);
}

int main() {
    string input = "abc";
    vector<string> result = getAllSubsequences(input);

    cout << "All subsequences of '" << input << "':" << endl;
    for (const string &subsequence : result) {
        cout << subsequence << endl;
    }

    return 0;
}
