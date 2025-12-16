#include "Dynamic Programming.h"

bool DP::wordBreak(string s, vector<string>& wordDict) {
    int size = s.size();
    vector<bool> dp(size + 1, false);
    dp[0] = true;
    string tmp;

    for (int i = 1; i <= size; i++) {
        tmp += s[i - 1];
        for (string str : wordDict) {
            int str_size = str.size();
            int tmp_size = tmp.size();
            if (tmp_size >= str_size) {
                string tmptmp = tmp.substr(tmp_size - str_size, str_size);
                if (tmptmp == str) {
                    if (dp[i - str_size] == true) {
                        dp[i] = true;
                    }
                }
            }
        }

    }


    return dp[size];
}