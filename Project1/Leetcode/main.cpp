#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"

int main() {
    string s = "leetcode";
    vector<string> str{ "leet", "code" };

    cout << DP::wordBreak(s, str);

    return 0;
}