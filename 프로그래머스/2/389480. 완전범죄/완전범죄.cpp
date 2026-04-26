#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    dp[0][0] = true;

    for (auto& item : info) {
        vector<vector<bool>> next(n, vector<bool>(m, false));

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[a][b]) continue;

                // A가 훔치는 경우
                int na = a + item[0];
                if (na < n) {
                    next[na][b] = true;
                }

                // B가 훔치는 경우
                int nb = b + item[1];
                if (nb < m) {
                    next[a][nb] = true;
                }
            }
        }

        dp = next;
    }

    int answer = n;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (dp[a][b]) {
                answer = min(answer, a);
            }
        }
    }

    return (answer == n) ? -1 : answer;
}