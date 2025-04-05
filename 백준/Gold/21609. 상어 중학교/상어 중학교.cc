#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring> 

using namespace std;
int board[21][21];
int N;

const vector<pair<int, int>> baseDir = {
	{-1, 0 },
	{0, 1 },
	{1, 0},
	{0, -1 }
};

struct groupInfo {
	vector<pair<int, int>> Group;
	int ZeroCnt = 0;
	int RowCnt = N;
	int ColCnt = N;
};

void ApplyRotation()
{
	int newBoard[21][21];
	for (int Row = 0; Row < N; Row++)
	{
		for (int Col = 0; Col < N; Col++)
		{
			int rCol = N - 1 - Col;
			newBoard[rCol][Row] = board[Row][Col];
		}
	}

	memcpy(board, newBoard, sizeof(newBoard));

	/*
	cout << "Applay R" << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}

void ApplyGravity()
{
	/*
	cout << "Before Applay G" << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	for (int Col = 0; Col < N; Col++)
	{
		for (int Row = N - 1; Row > 0; Row--)
		{
			if (board[Row][Col] == -2)
			{
				int r = Row - 1;
				while (r >= 0)
				{
					if (board[r][Col] == -1)
						break;
					else if (board[r][Col] >= 0)
					{
						board[Row][Col] = board[r][Col];
						board[r][Col] = -2;
						break;
					}
					r--;
				}
			}
		}
	}

	/*
	cout << "Applay G" << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}

void MaxUpdate(groupInfo* maxG, groupInfo* tmpG)
{
	maxG->Group = tmpG->Group;
	maxG->ZeroCnt = tmpG->ZeroCnt;
	maxG->RowCnt = tmpG->RowCnt;
	maxG->ColCnt = tmpG->ColCnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int colorNum;
	cin >> N >> colorNum;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> board[row][col];
		}
	}

	int sum = 0;
	while (true)
	{
		//가장 큰 블록을 찾는 과정
		groupInfo maxG;
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
			{
				if (board[row][col] == -1 || board[row][col] == 0 || board[row][col] == -2)
					continue;

				//bfs
				bool parent[400] = { false };
				queue<pair<int, int>> q;

				int color = board[row][col];

				q.push(make_pair(row, col));

				groupInfo tmp;

				while (!q.empty())
				{
					const auto& cur = q.front();
					q.pop();
					int posX = cur.first;
					int posY = cur.second;
					int pIdx = cur.first * N + cur.second;
					//큐 도는 동안 다른 곳에서 이미 했으면
					if (parent[cur.first * N + cur.second])
						continue;

					parent[pIdx] = true;
					tmp.Group.push_back(make_pair(posX, posY));

					if (board[posX][posY] == 0) tmp.ZeroCnt++;
					if (board[posX][posY] > 0 &&
						(tmp.RowCnt > posX || (tmp.RowCnt == posX && tmp.ColCnt > posY)))
					{
						tmp.RowCnt = posX;
						tmp.ColCnt = posY;
					}

					for (const auto& dir : baseDir)
					{
						//범위 확인
						if (posX + dir.first < 0 || posX + dir.first >= N || posY + dir.second < 0 || posY + dir.second >= N)
							continue;

						int curX = posX + dir.first;
						int curY = posY + dir.second;
						//색깔 확인
						if (board[curX][curY] != 0 && board[curX][curY] != color)
							continue;
						q.push(make_pair(curX, curY));
					}
				}

				//블록 못 찾았으면 끝내기
				if (tmp.Group.size() < 2)
					continue;

				//최대로 업데이트
				if (maxG.Group.size() < tmp.Group.size())
				{
					MaxUpdate(&maxG, &tmp);
				}
				else if (maxG.Group.size() == tmp.Group.size())
				{
					if (maxG.ZeroCnt < tmp.ZeroCnt)
					{
						MaxUpdate(&maxG, &tmp);
					}
					else if (maxG.ZeroCnt == tmp.ZeroCnt)
					{
						if (maxG.RowCnt < tmp.RowCnt)
						{
							MaxUpdate(&maxG, &tmp);
						}
						else if (maxG.RowCnt == tmp.RowCnt)
						{
							if (maxG.ColCnt < tmp.ColCnt)
							{
								MaxUpdate(&maxG, &tmp);
							}
						}
					}
				}
			}
		}

		/*
		for (const auto& g : maxG.Group)
		{
			cout << "{} " << g.first << " : " << g.second << "\n";
		}
		*/
		//블록 못 찾았으면 끝내기
		if (maxG.Group.size() < 2)
			break;

		sum += maxG.Group.size() * maxG.Group.size();

		//블록 초기화 과정
		for (const auto& p : maxG.Group)
		{
			board[p.first][p.second] = -2;
		}

		//중력 작용 과정
		ApplyGravity();

		//90 회전 과정
		ApplyRotation();

		//중력 작용 과정
		ApplyGravity();
	}

	cout << sum;

	return 0;
}