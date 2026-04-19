#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> dp(9);

    for (int k = 1; k <= 8; ++k) {

        int base = 0;
        for (int i = 0; i < k; ++i) {
            base = base * 10 + N;
        }
        dp[k].insert(base);

        for (int i = 1; i < k; ++i) {
            for (int a : dp[i]) {
                for (int b : dp[k - i]) {
                    dp[k].insert(a + b);
                    dp[k].insert(a - b);
                    dp[k].insert(a * b);
                    if (b != 0) dp[k].insert(a / b);
                }
            }
        }

        if (dp[k].find(number) != dp[k].end()) {
            return k;
        }
    }

    return -1;
}