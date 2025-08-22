#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0};

vector<vector<int>> board;
vector<vector<bool>> visited;
int max_sum = 0;
int max_value = 0;

void dfs(int r, int c, int sum, int stage)
{
    if (stage == 4)
    {
        max_sum = max(max_sum, sum);
        return;
    }

    if (sum + (4 - stage) * max_value <= max_sum) return;

    for (int i = 0; i < 4; i++)
    {
        if (stage == 2)
        {
            int nxtR = r + dx[i]; int nxtC = c + dy[i];
            if (nxtR < 0 || nxtR >= board.size() || nxtC < 0 || nxtC >= board[0].size() || visited[nxtR][nxtC]) continue;
            visited[nxtR][nxtC] = true;
            dfs(r, c, sum + board[nxtR][nxtC], stage + 1);
            visited[nxtR][nxtC] = false;
        }

        int nxtR = r + dx[i]; int nxtC = c + dy[i];
        if (nxtR < 0 || nxtR >= board.size() || nxtC < 0 || nxtC >= board[0].size() || visited[nxtR][nxtC]) continue;
        visited[nxtR][nxtC] = true;
        dfs(nxtR, nxtC, sum + board[nxtR][nxtC], stage + 1);
        visited[nxtR][nxtC] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;

    board.resize(row, vector<int>(col));
    visited.resize(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> board[i][j];
            max_value = max(max_value, board[i][j]);
        }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            visited[i][j] = true;
            dfs(i, j, board[i][j], 1);
            visited[i][j] = false;
        }

    cout << max_sum;
    return 0;
}