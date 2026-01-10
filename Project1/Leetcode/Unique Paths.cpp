#include "Dynamic Programming.h"

int factorial(int input) {
    if (input == 0) {
        return 1;
    }

    return factorial(input - 1) * input;
}
int DP::uniquePaths(int m, int n) {
    // int x = m - 1;
    // int y = n - 1;
    // return factorial(x + y) / (factorial(x) * factorial(y));
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
    dp[1][1] = 2;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];

}