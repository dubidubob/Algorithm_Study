#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(10, 0));

    // 초기값 세팅
    for (int digit = 1; digit <= 9; ++digit)
        dp[1][digit] = 1;

    // dp 계산
    for (int length = 2; length <= n; ++length) {
        for (int digit = 0; digit <= 9; ++digit) {
            if (digit - 1 >= 0)
                dp[length][digit] += dp[length - 1][digit - 1];
            if (digit + 1 <= 9)
                dp[length][digit] += dp[length - 1][digit + 1];
            dp[length][digit] %= MOD;
        }
    }

    // 결과 계산
    int answer = 0;
    for (int digit = 0; digit <= 9; ++digit) {
        answer += dp[n][digit];
        answer %= MOD;
    }

    cout << answer << "\n";
    return 0;
}
