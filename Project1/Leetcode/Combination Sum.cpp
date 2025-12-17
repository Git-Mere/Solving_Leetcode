#include "Dynamic Programming.h"

//static int help(set<vector<int>>& result, vector<int>& candidates, int target, vector<int>& selected, vector<int>& memo) {
//    if (target < 0) { return -1; }
//    if (target == 0) {
//        sort(selected.begin(), selected.end());
//        bool check = result.insert(selected).second;
//        return 1;
//    }
//    if (memo[target] != 0) {
//        return memo[target];
//    }
//
//    for (int num : candidates) {
//        selected.push_back(num);
//        memo[target] += help(result, candidates, target - num, selected, memo);
//        auto it = find(selected.begin(), selected.end(), num);
//        if (it != selected.end()) { selected.erase(it); }
//    }
//}
//
//vector<vector<int>> DP::combinationSum(vector<int>& candidates, int target) {
//    vector<vector<int>> result;
//    set<vector<int>> help_set;
//    vector<int> tmp;
//    vector<int> memo(target + 1, 0);
//
//    help(help_set, candidates, target, tmp, memo);
//
//    for (const auto& s : help_set) {
//        vector<int> v(s.begin(), s.end());
//        result.push_back(v);
//    }
//
//    return result;
//}

vector<vector<int>> DP::combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<set<vector<int>>> dp(target + 1, set<vector<int>>());


    for (int i = 1; i <= target; i++) {
        for (const int& num : candidates) {
            if (i - num > 0) {
                for (auto vec : dp[i - num]) {
                    vec.push_back(num);
                    sort(vec.begin(), vec.end());
                    dp[i].insert(vec);
                }
            }
            else if (i - num == 0) {
                dp[i].insert({ i });
            }
        }
    }

    for (const auto& vec : dp[target]) {
        vector<int> tmp(vec.begin(), vec.end());
        result.push_back(tmp);
    }
    


    return result;
}


//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//    vector<vector<vector<int>>> dp(target + 1);
//    dp[0].push_back(vector<int>()); // base
//
//    for (int c : candidates) {
//        for (int t = c; t <= target; ++t) {
//            for (auto& comb : dp[t - c]) {
//                vector<int> newComb = comb;
//                newComb.push_back(c);
//                dp[t].push_back(newComb);
//            }
//        }
//    }
//    return dp[target];
//}