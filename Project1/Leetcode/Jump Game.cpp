#include "Dynamic Programming.h"

bool DP::canJump(vector<int>& nums) {
    if (nums.size() == 1) {
        return true;
    }
    if (nums[0] == 0) {
        return false;
    }

    int size = nums.size();
    vector<bool> dp(size + 1, false);
    dp[0] = true;
    for (int i = 0; i < size; i++) {
        if (dp[i] == false) {
            return false;
        }
        int num = min(nums[i], size);
        
        for (int j = 1; j <= num; j++) {
            dp[i + j] = true;
        }
    }

    return dp[size - 1];
}