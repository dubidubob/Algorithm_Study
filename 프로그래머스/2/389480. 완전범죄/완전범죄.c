#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** info, size_t info_rows, size_t info_cols, int n, int m) {
    // 현재 가능한 상태들 저장
    bool dp[121][121] = {false};
    dp[0][0] = true;

    for (int i = 0; i < info_rows; i++) {
        bool next[121][121] = {false};

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[a][b]) continue;

                // A가 훔침
                int na = a + info[i][0];
                if (na < n) {
                    next[na][b] = true;
                }

                // B가 훔침
                int nb = b + info[i][1];
                if (nb < m) {
                    next[a][nb] = true;
                }
            }
        }

        // 다음 상태로 이동
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                dp[a][b] = next[a][b];
            }
        }
    }

    // A 흔적 최소 찾기
    int answer = n;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (dp[a][b]) {
                if (a < answer) answer = a;
            }
        }
    }

    return (answer == n) ? -1 : answer;
}