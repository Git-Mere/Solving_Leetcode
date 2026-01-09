#include "Dynamic Programming.h"

int DP::numDecodings(string s) {
    if (s[0] == '0') { return 0; }
    int size = s.size();
    vector<int> dp(size, 0);
    dp[0] = 1;
    for (int i = 1; i < size; i++) {
        if (s[i] == '0') {
            if (s[i - 1] != '1' && s[i - 1] != '2') {
                return 0;
            }

            if (dp[i - 1] > 1) {
                dp[i] = dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }

            continue;
        }

        if (s[i - 1] == '1' || (s[i - 1] == '2' && (s[i] - '0') < 7 && (s[i] - '0') > 0)) {
            int add = 0;
            if (i - 2 < 0) {
                add = 1;
            }
            else {
                add = dp[i - 2];
            }
            dp[i] = dp[i - 1] + add;
            continue;
        }
        dp[i] = dp[i - 1];
    }

    return dp[size - 1];

}