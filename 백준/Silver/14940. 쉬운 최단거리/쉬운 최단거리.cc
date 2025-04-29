#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1001;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, M; 
bool visited[MAX][MAX] = { false };
int board[MAX][MAX];

struct node {
	int row;
	int col;
};

bool isNodeVaild(node n) {
	return n.row >= 0 && n.row < N && n.col >= 0 && n.col < M;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	node start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				start.row = i;
				start.col = j;
			}
		}
	}

	queue<node> q;
	q.push(start);
	board[start.row][start.col] = 0;
	visited[start.row][start.col] = true;

	while (!q.empty()) {
		node cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			node nxt = { cur.row + dx[i], cur.col + dy[i] };
			if (isNodeVaild(nxt) && !visited[nxt.row][nxt.col] && board[nxt.row][nxt.col] == 1) {
				board[nxt.row][nxt.col] = board[cur.row][cur.col] + 1;
				visited[nxt.row][nxt.col] = true;
				q.push(nxt);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && !visited[i][j])
				cout << -1 << " ";
			else
				cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
