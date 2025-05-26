#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

struct pos {
    int row;
    int col;
};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> house;

    for (int r = 0; r < n; r++) {
        string word;
        cin >> word;
        for (int c = 0; c < n; c++) {
            board[r][c] = word[c]-'0';
        }
    }
    
    int cnt = 0;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 0 || visited[r][c]) continue;
            
            house.push_back(0);
            pos start = { r, c };

            queue <pos> q;
            q.push(start);

            while (!q.empty()) {
                pos cur = q.front(); q.pop();
                if (visited[cur.row][cur.col])
                    continue;
                visited[cur.row][cur.col] = true;
                house[cnt]++;
                
                for (int i = 0; i < 4; i++) {
                    pos nxt = { cur.row + dx[i], cur.col + dy[i]};
                    if (nxt.row < 0 || nxt.row >= n || nxt.col < 0 || nxt.col >= n) continue;
                    if (board[nxt.row][nxt.col] == 0 || visited[nxt.row][nxt.col]) continue;
                    q.push(nxt);
                }
            }
            cnt++;
        }
    }

    cout << cnt << "\n";
    sort(house.begin(), house.end());
    for (int h : house) {
        cout << h << "\n";
    }

    return 0;
}
