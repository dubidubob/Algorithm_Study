#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0,0,1, -1};

struct pos {
	int x;
	int y;
	int time;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int n, m;
	cin >> m >> n;

	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	queue<pos> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i, j, 0 });
		}
	}

	int maxCnt = 0;
	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		if (visited[cur.x][cur.y]) continue;
		visited[cur.x][cur.y] = true;
		board[cur.x][cur.y] = 1;
		maxCnt = max(maxCnt, cur.time);

		for (int i = 0; i < 4; i++) {
			pos nxt = { cur.x + dx[i], cur.y + dy[i], cur.time+1 };
			if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m) continue;
			if (visited[nxt.x][nxt.y] || board[nxt.x][nxt.y] == -1) continue;
			q.push(nxt);
		}
	}

	bool isFailed = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				isFailed = true;
				i = n;
				break;
			}
		}
	}

	if (isFailed)
		cout << -1;
	else
		cout << maxCnt;

	return 0;
}