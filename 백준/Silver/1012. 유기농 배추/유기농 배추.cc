#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

struct pos {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<bool>> ground(n, vector<bool>(m, 0));
        for (int i = 0; i < k; i++) {
            int y, x;
            cin >> y >> x;
            ground[x][y] = true;
        }

        int count = 0;
        for (int i = 0; i < ground.size(); i++) {
            for (int j = 0; j < ground[0].size(); j++) {
                if (ground[i][j]) {
                    count++;

                    queue<pos> q;
                    q.push({ i, j });
                    while (!q.empty()) {
                        pos cur = q.front(); q.pop();
                        for (int e = 0; e < 4; e++) {
                            pos nxt = { cur.x + dx[e], cur.y + dy[e] };
                            if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m) continue;
                            if (ground[nxt.x][nxt.y]) {
                                ground[nxt.x][nxt.y] = false;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }
        }

        cout << count<<"\n";
    }
    
    return 0;
}
