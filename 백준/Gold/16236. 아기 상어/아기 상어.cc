#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // std::sort를 위해 필요

using namespace std;

// 상, 좌, 우, 하 (문제의 우선순위와는 별개로 BFS 탐색 순서 결정)
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

// 위치와 시간을 저장하는 구조체
struct pos {
    int x;
    int y;
    int time; // 현재 위치까지 도달하는 데 걸린 시간 (거리)
};

// 물고기 선택을 위한 커스텀 비교 함수
// 1. time이 짧은 순 (최단 거리)
// 2. time이 같으면 x가 작은 순 (가장 위쪽)
// 3. time과 x가 같으면 y가 작은 순 (가장 왼쪽)
bool compareFish(const pos& a, const pos& b) {
    if (a.time != b.time) {
        return a.time < b.time;
    }
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    // 입출력 속도 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 보드 상태 저장 (0: 빈 칸, 1~6: 물고기, 9: 아기 상어)
    vector<vector<int>> board(n, vector<int>(n));
    pos shark_pos; // 아기 상어의 현재 위치

    // 보드 초기화 및 상어 초기 위치 찾기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark_pos = {i, j, 0}; // 상어의 초기 위치
                board[i][j] = 0; // 상어가 있던 자리는 빈 칸이 됨
            }
        }
    }

    int shark_size = 2;       // 아기 상어의 초기 크기
    int eaten_count = 0;      // 현재 크기에서 먹은 물고기 수
    int total_time = 0;       // 총 이동 시간

    // 더 이상 먹을 물고기가 없을 때까지 반복
    while (true) {
        // BFS를 위한 초기화: 각 칸까지의 최단 거리를 저장 (방문 여부도 겸함)
        // -1: 미방문, 0 이상: 시작점으로부터의 거리
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pos> q;
        
        // BFS 시작점 설정 (현재 상어 위치)
        q.push(shark_pos);
        dist[shark_pos.x][shark_pos.y] = 0; // 시작점의 거리는 0

        // 현재 BFS에서 발견된 모든 먹을 수 있는 물고기 후보들
        vector<pos> edible_fish_candidates; 
        
        // BFS 수행
        while (!q.empty()) {
            pos cur = q.front();
            q.pop();

            // 만약 현재 칸의 거리가 이미 발견된 가장 짧은 물고기 거리보다 크다면,
            // 이 경로로 더 탐색할 필요가 없음 (최적화)
            // 이 최적화는 모든 후보를 찾고 정렬하는 방식에서는 사실 필수는 아님.
            // 하지만 불필요한 탐색을 줄여줄 수 있음.
            // (그러나 여기서는 모든 가능한 물고기를 찾는 것이 더 중요하므로 주석 처리하거나,
            //  모든 물고기를 찾은 후 최소 거리로 필터링하는 방식으로 대체)

            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                // 1. 지도 경계 벗어나는지 확인
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                // 2. 이미 방문한 칸인지 확인
                if (dist[nx][ny] != -1) continue;

                // 3. 상어보다 큰 물고기가 있는 칸은 지나갈 수 없음
                if (board[nx][ny] > shark_size) continue;

                // 4. 이동 가능한 칸인 경우 (빈 칸이거나 상어 크기 이하의 물고기)
                dist[nx][ny] = cur.time + 1; // 거리 업데이트
                q.push({nx, ny, dist[nx][ny]}); // 큐에 추가

                // 5. 만약 상어보다 작은 물고기가 있다면 먹을 수 있는 후보에 추가
                if (board[nx][ny] != 0 && board[nx][ny] < shark_size) {
                    edible_fish_candidates.push_back({nx, ny, dist[nx][ny]});
                }
            }
        }

        // BFS 종료 후: 먹을 수 있는 물고기가 있는지 확인
        if (edible_fish_candidates.empty()) {
            // 더 이상 먹을 물고기가 없으면 시뮬레이션 종료
            break;
        }

        // 먹을 물고기 후보들을 우선순위에 따라 정렬
        sort(edible_fish_candidates.begin(), edible_fish_candidates.end(), compareFish);

        // 가장 우선순위가 높은 물고기를 선택
        pos chosen_fish = edible_fish_candidates[0];

        // 총 이동 시간 업데이트
        total_time += chosen_fish.time;

        // 보드 상태 업데이트: 물고기 먹기
        board[chosen_fish.x][chosen_fish.y] = 0; // 물고기가 있던 자리는 빈 칸이 됨

        // 상어 위치 업데이트
        shark_pos = {chosen_fish.x, chosen_fish.y, 0}; // 상어는 먹은 물고기 위치로 이동

        // 상어 성장 조건 확인 및 업데이트
        eaten_count++;
        if (eaten_count == shark_size) {
            shark_size++;
            eaten_count = 0; // 성장했으므로 다시 0부터 카운트
        }
    }

    // 최종 결과 출력
    cout << total_time << endl;

    return 0;
}