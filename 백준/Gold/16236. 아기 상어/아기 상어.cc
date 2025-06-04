#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    Pos shark{ -1, -1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = { i, j };
                board[i][j] = 0; // 빈 칸으로 바꿔 두기
            }
        }
    }

    int sharkSize = 2;
    int eatCnt = 0;       // 현재 사이즈만큼 먹으면 크기 증가
    int totalTime = 0;    // 정답(모든 물고기를 먹을 때까지 걸린 시간)

    // 4방향
    const int dx[4] = { -1,  0, 1,  0 };
    const int dy[4] = {  0,  1, 0, -1 };

    while (true) {
        // 1) 매차례마다 "방문 표시" 초기화, 최단 거리 BFS 탐색 준비
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<Pos,int>> q; // {좌표, 현재까지 시간}
        visited[shark.x][shark.y] = true;
        q.push({ shark, 0 });

        int minDist = INT_MAX;
        vector<Pos> fishList; 
        // fishList 에는 "같은 최소거리(minDist)에 있는 물고기들을 모두 모아두고,
        // 나중에 행, 열 오름차순 정렬 후 맨 앞에 있는 물고기를 고를 것"

        while (!q.empty()) {
            auto [cur, dist] = q.front();
            q.pop();

            // 만약 지금까지 찾은 물고기 최단거리가 dist보다 작다면
            // 더 이상 이 레벨 이후(q의 깊이)로는 갈 필요가 없다.
            if (dist > minDist) break;

            // 현재 칸이 먹을 수 있는 물고기인 경우(0 < board < sharkSize)
            if (board[cur.x][cur.y] > 0 && board[cur.x][cur.y] < sharkSize) {
                // 첫 물고기를 발견한 순간: minDist를 갱신하고, fishList에 넣기
                if (dist < minDist) {
                    minDist = dist;
                    fishList.clear();
                    fishList.push_back(cur);
                }
                else if (dist == minDist) {
                    // 같은 거리의 물고기는 똑같이 후보로 추가
                    fishList.push_back(cur);
                }
                // ★ 이 칸에서 더 깊이 탐색할 필요가 없다.
                // (거리(dist) > 물고기까지 최소거리였으므로)
                continue;
            }

            // 물고기가 아니거나 sharkSize보다 큰 물고기가 아니라 BFS 확장
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny] > sharkSize) continue; 
                // 상어 크기보다 큰 물고기는 못 지나감

                visited[nx][ny] = true;
                q.push({ {nx, ny}, dist + 1 });
            }
        }

        // 2) BFS가 끝났는데, 잡을 수 있는 물고기가 없다면 while문 종료
        if (fishList.empty()) {
            break; 
        }

        // 3) fishList에는 “가장 가까운 물고기들(거리 == minDist)”이 들어있다.
        //    여기서 row(x) 오름차순, col(y) 오름차순으로 정렬 → 맨 앞이 진짜 먹을 물고기
        sort(fishList.begin(), fishList.end(), [](const Pos &a, const Pos &b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });
        Pos eat = fishList.front();

        // 4) 상어 이동 및 시간 증가, board 업데이트, 먹은 수 증가
        totalTime += minDist;       // 이동한 시간 누적
        shark = eat;                // 상어 위치를 “먹은 물고기 위치”로 옮김
        board[eat.x][eat.y] = 0;    // 물고기를 먹었으므로 0으로 바꿈

        eatCnt++;
        if (eatCnt == sharkSize) {
            sharkSize++;
            eatCnt = 0;
        }
        // ↪ 먹고 나면 다시 while(true) 돌아가서, 새 위치에서 BFS 재탐색
    }

    cout << totalTime << "\n";
    return 0;
}
