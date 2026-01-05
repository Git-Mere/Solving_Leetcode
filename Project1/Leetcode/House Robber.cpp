#include "Dynamic Programming.h"

int DP::rob(vector<int>& nums) {
    int size = nums.size();
    if (size < 3) {
        return *max_element(nums.begin(), nums.end());
    }

    vector<int> dp(size, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = dp[0] + nums[2];
    for (int i = 3; i < size; i++) {
        dp[i] = max(dp[i - 3] + nums[i], dp[i - 2] + nums[i]);
    }
    int result = dp[size - 1] > dp[size - 2] ? dp[size - 1] : dp[size - 2];
    return result;
}