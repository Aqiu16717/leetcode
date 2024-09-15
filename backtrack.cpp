#include <iostream>

using namespace std;

void backtrack(string str, int start) {
    if (start == str.size()) {
        return;
    }
    for (int i = start; i < str.size(); ++i) {
        cout << "start:" << start << " " << "i:" << i << " ";
        cout << str.substr(start, i - start + 1) << endl;
        backtrack(str, i + 1);
        // backtrack(str, i);
    }
}

int main() {
    string str;
    // str = "abcd";
/*
start:0 i:0 a
    start:1 i:1 b
        start:2 i:2 c
    start:1 i:2 bc
start:0 i:1 ab
        start:2 i:2 c
start:0 i:2 abc
*/
    str = "abc";
    backtrack(str, 0);
    return 0;
}
