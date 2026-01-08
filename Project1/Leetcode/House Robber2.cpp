#include "Dynamic Programming.h"

int help(vector<int>& nums) {
    int size = nums.size();
    if (size < 4) {
        return *max_element(nums.begin(), nums.end());
    }

    vector<int> dp(size, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = dp[0] + nums[2];
    int add = 0;
    bool flag = false;
    for (int i = 3; i < size; i++) {
        if (dp[i - 3] + nums[i] > dp[i - 2] + nums[i]) {
            add = dp[i - 3] + nums[i];
            if (i - 3 == 0 || i - 3 == 2) {
                flag = true;
            }
        }
        else {
            add = dp[i - 2] + nums[i];
            if (i - 2 == 0 || i - 2 == 2) {
                flag = true;
            }
        }
        dp[i] = add;
    }

    int result = 0;
    if (flag) {
        result = *max_element(dp.begin(), dp.end() - 1);
    }
    else {
        result = *max_element(dp.begin(), dp.end());

    }

    return result;
}

int DP::rob2(vector<int>& nums) {
    int can1 = help(nums);
    reverse(nums.begin(), nums.end());
    int can2 = help(nums);
    return max(can1, can2);
}