#include <string>

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
    // monotoneIncreasingDigits(123);
    // monotoneIncreasingDigits(456);
    monotoneIncreasingDigits(987);
    return 0;
}
