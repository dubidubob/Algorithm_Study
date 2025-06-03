#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0,0,1, -1};

struct pos {
	int x;
	int y;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int n, m;
	cin >> m >> n;

	vector<vector<int>> board(n, vector<int>(m));
	queue<pos> q;
	int unripen_t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i, j });
			else if (board[i][j] == 0)
				unripen_t++;
		}
	}

	int maxCnt = 0;
	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		maxCnt = max(maxCnt, board[cur.x][cur.y]);

		for (int i = 0; i < 4; i++) {
			pos nxt = { cur.x + dx[i], cur.y + dy[i] };
			if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m) continue;
			if (board[nxt.x][nxt.y] == 0) {
				board[nxt.x][nxt.y] = board[cur.x][cur.y] + 1;
				q.push(nxt);
				unripen_t--;
			}
		}
	}

	if(unripen_t > 0)
		cout << -1;
	else
		cout << maxCnt-1;

	return 0;
}