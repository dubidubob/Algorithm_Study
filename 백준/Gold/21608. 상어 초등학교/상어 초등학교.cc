#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <map>       // for storing favorite_friends (optional, but good for clarity)

using namespace std;

struct pos {
    int x;
    int y;

    // 문제의 규칙 3, 4에 따라 행 우선, 열 우선으로 정렬되도록 연산자 오버로딩
    bool operator <(const pos& other) const {
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

const int dx[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
const int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    int board[21][21] = { 0 }; // 0: 빈 칸, 학생 번호
    map<int, vector<int>> favorite_friends; // 학생 ID별 좋아하는 친구 목록

    // 학생 배치 순서를 먼저 저장하고 처리하는 것이 일반적
    vector<int> student_order(n * n);

    for (int i = 0; i < (n * n); i++) {
        int cur_student_id; 
        cin >> cur_student_id; // 현재 앉힐 학생 ID

        student_order[i] = cur_student_id; // 순서 기록

        vector<int> temp_friends(4);
        for (int j = 0; j < 4; j++) {
            cin >> temp_friends[j];
        }
        favorite_friends[cur_student_id] = temp_friends; // 좋아하는 친구들 저장
    }

    // 학생 배치 순서대로 처리
    for (int cur_student_id : student_order) { // cur 대신 cur_student_id로 변경 (명확성)
        // 매번 학생을 앉힐 때마다 최적의 자리를 찾기 위해 초기화
        int max_friends_count = -1; // 초기값을 -1로 설정하여 어떤 유효한 값이든 첫 후보가 될 수 있도록 함
        int max_empty_count = -1;   // 초기값을 -1로 설정
        
        vector<pos> candidates; // 현재 학생에게 최적의 조건을 만족하는 모든 후보지

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // 이미 학생이 앉아있는 칸은 건너뛴다.
                if (board[r][c] != 0) continue;

                int current_friends_count = 0; // 이 칸에 앉았을 때 인접한 좋아하는 친구 수
                int current_empty_count = 0;   // 이 칸에 앉았을 때 인접한 빈 칸 수

                // 4방향 탐색
                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k];
                    int nc = c + dy[k];

                    // 보드 범위 체크
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                    // 인접한 칸이 비어있는지 확인
                    if (board[nr][nc] == 0) {
                        current_empty_count++;
                    } 
                    // 인접한 칸에 학생이 앉아있다면, 그 학생이 현재 앉힐 학생의 친구인지 확인
                    else {
                        // **핵심 수정: board[r][c] 대신 board[nr][nc]의 학생이 친구인지 확인해야 합니다.**
                        for (int f : favorite_friends[cur_student_id]) { // friends[cur] 대신 favorite_friends[cur_student_id] 사용 (map)
                            if (board[nr][nc] == f) { 
                                current_friends_count++;
                                break; // 친구 한 명 찾았으니 다음 인접 칸으로
                            }
                        }
                    }
                }

                // 규칙에 따라 최적의 자리 업데이트
                // 1. 좋아하는 친구 수가 더 많으면 무조건 갱신
                if (current_friends_count > max_friends_count) {
                    candidates.clear(); // 새로운 더 좋은 조건이므로 이전 후보들 제거
                    max_friends_count = current_friends_count;
                    max_empty_count = current_empty_count; // 새로운 max_friends에 맞는 max_empty 갱신
                    candidates.push_back({ r, c });
                }
                // 2. 좋아하는 친구 수가 같으면 빈 칸이 더 많은지 확인
                else if (current_friends_count == max_friends_count) {
                    if (current_empty_count > max_empty_count) {
                        candidates.clear(); // 새로운 더 좋은 조건이므로 이전 후보들 제거
                        max_empty_count = current_empty_count;
                        candidates.push_back({ r, c });
                    }
                    // 3. 좋아하는 친구 수도 같고 빈 칸도 같으면, 후보에 추가 (나중에 sort로 행/열 순서 따름)
                    else if (current_empty_count == max_empty_count) {
                        candidates.push_back({ r, c });
                    }
                }
            }
        }
        
        // 정렬: 규칙 3(행 번호), 규칙 4(열 번호) 적용을 위해
        // pos struct의 operator< 덕분에 자동으로 행 우선, 열 우선으로 정렬됩니다.
        sort(candidates.begin(), candidates.end()); 
        
        // 가장 첫 번째 후보 (최적의 자리)에 학생 배치
        pos seat = candidates[0];
        board[seat.x][seat.y] = cur_student_id;

        // --- 디버그 출력 코드 (제출 시에는 제거해야 합니다) ---
        // cout << cur_student_id << " \n"; 
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         cout << board[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n"; // 칸 구분을 위해 추가
        // --- 디버그 출력 코드 끝 ---
    }

    // 최종 만족도 계산
    long long total_satisfaction = 0; // 점수 합계를 위해 long long 사용
    int score_map[5] = {0, 1, 10, 100, 1000}; // 인접한 친구 수에 따른 점수표

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int student_id = board[r][c]; // 현재 칸에 앉아있는 학생 ID
            int adjacent_friends_count = 0;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                // board[r][c]에 앉아있는 학생(student_id)의 친구 목록과 인접 칸(board[nr][nc])의 학생 비교
                for (int f : favorite_friends[student_id]) { 
                    if (board[nr][nc] == f) {
                        adjacent_friends_count++;
                        break; 
                    }
                }
            }
            total_satisfaction += score_map[adjacent_friends_count];
        }
    }

    cout << total_satisfaction << "\n";

    return 0;
}