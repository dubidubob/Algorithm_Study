#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    //각 아이템 정보
    vector<pair<int, int>> items(1, {0, 0});
    int w, v;

		//핉터 1: 아이템 정보 저장
    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        items.push_back({w, v});
    }

    // 필터 2 : 무게에 따라 정렬, C++ sort!
    sort(items.begin(), items.end());

    // 필터 3 : 아이템 키마다 준서 무게 게이지가 차있다.
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // 냅색 알고리즘
    for (int i = 1; i <= n; i++) {// N개 아이템 순회
        for (int j = 0; j <= k; j++) { // Kkg 물건 제한 
            if (j - items[i].first >= 0) {// Wkg 물건 검사
                dp[i][j] = max(dp[i - 1][j - items[i].first] + items[i].second, dp[i - 1][j]);// V 가치 비교
            } else {//넘으면 bye
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}
