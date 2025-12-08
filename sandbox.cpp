#include <vector>

//Fibonacci
int body(int n){
    std::vector<int> memo(n + 1, -1);
    return fib(n, memo);
}

int fib(int n, std::vector<int>& memo){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

    return memo[n];
}

int fib(int n){
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

//Coin changer
int coinChange(std::vector<int>& coins, int amount){
    //동전은 1,2,5원짜리만 있음.
    if(amount < 0){
        return -1;
    }
    if(amount == 0){
        return 0;
    }

    int next = 1'000'000;
    for(int coin : coins){
        if(amount - coin >= 0){
            int test = coinChange(coins, amount - coin);
            if(test != -1){
                next = std::min(next, test + 1);
            }
        }
    }

    return next == 1000000 ? -1 : next;
}

//memoization
int coinChange(std::vector<int>& coins, int amount, std::vector<int>& memo){
    //동전은 1,2,5원짜리만 있음.
    if(amount < 0){
        return -1;
    }
    if(amount == 0){
        return 0;
    }
    if(memo[amount] != INT_MAX){
        return memo[amount];
    }

    for(int coin : coins){
        if(amount - coin >= 0){
            int test = coinChange(coins, amount - coin, memo);
            if(test >= 0){
                memo[amount] = std::min(memo[amount], test + 1);
            }
        }
    }

    return memo[amount] == INT_MAX ? -1 : memo[amount];
}

//dp
int coinChange(std::vector<int>& coins, int amount){
    //동전은 1,2,5원짜리만 있음.
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++){
        for(int coin : coins){
            if(i - coin >= 0){
                dp[i] = std::min(dp[i - coin] + 1, dp[i]);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int tiling(int n){
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int longestEqualRunRec(const std::vector<int>& a, int l, int r) {
    if (l == r) return 1;                // 원소 하나면 길이 1

    int mid = (l + r) / 2;

    // 1) 왼쪽, 오른쪽에서의 최대 길이 (Divide & Conquer)
    int leftBest  = longestEqualRunRec(a, l, mid);
    int rightBest = longestEqualRunRec(a, mid + 1, r);

    // 2) 경계를 가로지르는 cross 부분 계산
    int crossBest = 1;

    // 경계 양쪽 값이 같을 때만 cross가 의미가 있음
    if (a[mid] == a[mid + 1]) {
        int val = a[mid];

        // mid에서 왼쪽으로 같은 값이 얼마나 이어지는지
        int i = mid;
        while (i >= l && a[i] == val) {
            --i;
        }
        int leftLen = mid - i;           // (mid - i)개

        // mid+1에서 오른쪽으로 같은 값이 얼마나 이어지는지
        int j = mid + 1;
        while (j <= r && a[j] == val) {
            ++j;
        }
        int rightLen = j - (mid + 1);    // (j - (mid+1))개

        crossBest = leftLen + rightLen;  // 경계를 넘는 전체 길이
    }

    // 3) 셋 중 최대가 이 구간 [l, r] 의 답
    return std::max({leftBest, rightBest, crossBest});
}

// 외부에서 호출하는 편한 wrapper
int longestEqualRun(const std::vector<int>& a) {
    if (a.empty()) return 0;
    return longestEqualRunRec(a, 0, static_cast<int>(a.size()) - 1);
}


#include <bits/stdc++.h>
using namespace std;

// k번째 원소 찾기 (k는 1-based)
// arr1, arr2 는 정렬되어 있다고 가정
int findKthElement(const vector<int>& arr1, const vector<int>& arr2, int k) {
    // 항상 arr1이 더 짧게 맞추기
    if (arr1.size() > arr2.size()) {
        return findKthElement(arr2, arr1, k);
    }

    int m = static_cast<int>(arr1.size());
    int n = static_cast<int>(arr2.size());

    // i 개를 arr1에서, j = k - i 개를 arr2에서 뽑는다고 할 때
    // j가 0..n 범위에 들어가도록 i의 범위를 제한
    int left  = max(0, k - n);
    int right = min(k, m);

    while (left <= right) {
        int i = (left + right) / 2; // arr1에서 뽑는 개수
        int j = k - i;              // arr2에서 뽑는 개수

        // 경계값 처리 (파이썬의 -inf / +inf 역할)
        int arr1_left  = (i > 0) ? arr1[i - 1] : INT_MIN;
        int arr1_right = (i < m) ? arr1[i]     : INT_MAX;
        int arr2_left  = (j > 0) ? arr2[j - 1] : INT_MIN;
        int arr2_right = (j < n) ? arr2[j]     : INT_MAX;

        // 올바른 partition 인지 확인
        if (arr1_left <= arr2_right && arr2_left <= arr1_right) {
            // 왼쪽 파티션의 최댓값이 바로 k번째 원소
            return max(arr1_left, arr2_left);
        }

        // partition 조정 (binary search)
        if (arr1_left > arr2_right) {
            // arr1 쪽이 너무 많음 → 왼쪽으로 줄이기
            right = i - 1;
        } else {
            // arr2 쪽이 너무 많음 → arr1에서 더 많이 가져오기
            left = i + 1;
        }
    }

    // 여기까지 오면 로직에 문제가 있는 것. (정상 입력이면 도달 X)
    throw runtime_error("Invalid input or k");
}

find_kth(A, a_start, m,  B, b_start, n,  k):

    BASE:
        # 한 배열이 비었으면, 다른 배열의 k번째가 답
        if m == 0:
            return B[b_start + k - 1]
        if n == 0:
            return A[a_start + k - 1]

        # k == 1 이면 두 배열의 첫 원소 중 더 작은 게 전체 k번째
        if k == 1:
            return min(A[a_start], B[b_start])

    SPLIT:
        # A에서 i개, B에서 j개를 "후보"로 보고 잘라낼지 말지 결정
        i = min(k // 2, m)          # A에서 볼 개수
        j = k - i                   # B에서 볼 개수 (i + j = k, j <= n 보장)

        A_cut = A[a_start + i - 1]  # A 쪽에서 기준값
        B_cut = B[b_start + j - 1]  # B 쪽에서 기준값

    REC_CALLS + COMBINE:
        if A_cut <= B_cut:
            # A의 앞 i개는 전체 k번째보다 "작거나 같으므로"
            # 더 이상 후보가 아님 → 버리고, k도 i만큼 줄임
            # 새 문제 P1 = (A[i..], B, k-i)
            return find_kth(A, a_start + i, m - i,
                            B, b_start,       n,
                            k - i)
        else:
            # B의 앞 j개를 버리고, k를 j만큼 줄임
            # 새 문제 P2 = (A, B[j..], k-j)
            return find_kth(A, a_start,       m,
                            B, b_start + j,   n - j,
                            k - j)





int missing_number(std::vector<int>& data, int low, int high){
    if(low == high){                                 //base
        return low;
    }

    int mid = low + high / 2;                       //split

    int count = 0;
    for(int x : data){
        if(low <= x && x <= mid){
            count++;
        }
    }
    int expected_count = mid + 1;

    if(count == expected_count){                    //combine
        return missing_number(data, mid + 1, high); //recursive call
    }
    else{
        return missing_number(data, low, mid);
    }


}

int MSoAD(std::vector<int> A, std::vector<int> B){
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<std::pair<int, int>> S;
    for(int i = 0; i < A.size(); i++){
        std::pair<int, int> v = {A[i], B[i]};
        S.push_back(v);
    }

    int total = 0;
    for(auto a : S){
        total += abs(a.first - a.second);
    }

    return total;

}

Tiling 문제
1) Recurrence
Let dp[x] = Number of methods in tiling for x

Base:
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

for x >= 3
    dp[x] = dp[x - 1] + dp[x - 2] + dp[x - 3];

So:
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[x] = dp[x - 1] + dp[x - 2] + dp[x - 3]; for x >= 3


2) Recursive version (with memoization)
int tiling(int remain_tile, std::vector<int> memo){
    if (remain_tile < 0) {return 0;}
    if(remain_tile == 0){
        return 1;
    }
    else if(remain_tile == 1){
        return 1;
    }
    else if(remain_tile == 2){
        return 2;
    }

    if(memo[remain_tile] != -1){
        return memo[remain_tile];
    }

    memo[remain_tile] = tiling(remain_tile - 1, tile) + tiling(remain_tile - 2, tile) + tiling(remain_tile - 3, tile);
    
    return memo[remain_tile];
}

3) Iterative _dp
int tiling(int remain_tile){
    std::vector<int> dp(remain_tile + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= remain_tile; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[remain_tile];
}



int max_long(std::vector<int> data, int l, int r){
    Base:
        if(l == r){
            return 1;
        }

    Split:
        int mid = (l + r) / 2;
        p1 = [l, mid];
        p2 = [mid + 1, r];

    Rec_calls:
        left_best = max_long(data, l, mid);
        right_best = max_long(data, mid + 1, r);

    Combine:
        cross_best = 1;

        if(data[mid] == data[mid + 1]){
            i = mid;
            leftlen = 0;
            while(i >= l && data[i] == data[mid]){
                leftlen++;
                i--;
            }

            j = mid + 1
            rightLen = 0
            while j <= r and A[j] == A[mid]:
                rightLen += 1
                j += 1

            crossBest = leftLen + rightLen
        }

    return max(leftBest, rightBest, crossBest)

}

mincost ticket 문제
1) Recurrence
Let dp[x] = minimum cost for having trip in x days

Base:
    dp[0] = 0;

for x > 0
    if(There is a trip in x days)
        dp[x] = min(dp[x - cost in a cost array] + costs[corresponing cost]...);
    else
        dp[x] = dp[x - 1]

So:
    dp[0] = 0;
    dp[x] = if(There is a trip in x days)
                dp[x] = min(dp[x - cost in a cost array] + costs[corresponing cost]...);
            else
                dp[x] = dp[x - 1]

2)Recursive version(with memoization)
vector<int> travel;     // travel[i] = 1 이면 i일에 여행
vector<int> costs;      // size = 3
vector<int> memo;       // memo[day] = day까지 최소비용, -1이면 아직 계산 안 됨

int solve(int day) {
    if (day <= 0) return 0;

    if (memo[day] != -1) return memo[day];

    if (!travel[day]) {
        // 여행 없는 날 → 그냥 이전 날과 동일
        memo[day] = solve(day - 1);
        return memo[day];
    }

    int  d1 = solve(day - 1)  + costs[0];   // 1-day pass
    int  d7 = solve(day - 7)  + costs[1];   // 7-day pass
    int d30 = solve(day - 30) + costs[2];   // 30-day pass

    memo[day] = min({d1, d7, d30});
    return memo[day];
}

// kick-start
int mincostTickets(vector<int>& days, vector<int>& costsInput) {
    int lastDay = *max_element(days.begin(), days.end());

    travel.assign(lastDay + 1, 0);
    for (int d : days) travel[d] = 1;

    memo.assign(lastDay + 1, -1);
    return solve(lastDay);
}

int min_cost(std::vector<int>& days, std::vector<int>& costs){
    int size = *max_element(days.begin(), days.end()) + 1;
    std::vector<int> dp(size, 0);
    dp[0] = 0;

    for(int i = 1; i <= size; i++){
        if(days.find(i) == days.end()){
            dp[i] = dp[i - 1];
        }
        else{
            dp[i] = std::min({dp[x - cost in a cost array] + costs[corresponing cost]...})
        }
    }
    return dp[size];
}

int find_kth_element(arr1, arr2, k){
    Base:

}