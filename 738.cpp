#include <string>
#include <cassert>

int monotoneIncreasingDigits(int N) {
    std::string strN = std::to_string(N);
    int marker = strN.size();
    for (int i = strN.size() - 1; i > 0; --i) {
        if (strN[i - 1] > strN[i]) {
            marker = i;
            strN[i - 1]--;
        }
    }
    
    for (int i = marker; i < strN.size(); ++i) {
        strN[i] = '9';
    }
    
    return std::stoi(strN);
}


int main(int argc, char const *argv[])
{
    int ret;
    ret = monotoneIncreasingDigits(123);
    assert(ret == 123);
    ret = monotoneIncreasingDigits(322);
    assert(ret == 299);
    // ret = monotoneIncreasingDigits(456);
    // ret = monotoneIncreasingDigits(987);
    ret= monotoneIncreasingDigits(100);
    assert(ret == 99);
    return 0;
}
