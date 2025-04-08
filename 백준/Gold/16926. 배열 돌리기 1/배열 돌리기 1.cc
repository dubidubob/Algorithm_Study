#include <iostream>
using namespace std;

int board[300][300];
int totalRotate;
int N, M;
void rotateBoard(const int& level)
{
	int rowWall = N - level * 2;
	int colWall = M - level * 2;
	int levelTotal = (rowWall - 1) * 2 + (colWall - 1) * 2;
	int tmpRotate = totalRotate % levelTotal;
	int rowLast = rowWall + level - 1;
	int colLast = colWall + level - 1;

	int posX = level;
	int posY = level;
	for (int idx = 0; idx < tmpRotate; idx++)
	{
		int even = board[posX][posY];
		int odd = even;
		bool isEven = false;
		for (int ix = 0; ix < levelTotal; ix++)
		{
			int tmpX = posX;
			int tmpY = posY;	

			//다음 노드 서치
			if (posY == level && posX >= level && posX < rowLast)
				tmpX++;
			else if (posX == rowLast && posY >= level && posY < colLast)
				tmpY++;
			else if (posY == colLast && posX <= rowLast && posX > level)
				tmpX--;
			else if (posX == level && posY <= colLast && posY > level)
				tmpY--;

			//노드 이동
			if (isEven)
			{
				even = board[tmpX][tmpY];
				board[tmpX][tmpY] = odd;
				isEven = false;
			}
			else
			{
				odd = board[tmpX][tmpY];
				board[tmpX][tmpY] = even;
				isEven = true;
			}

			//검사 노드 업데이트
			posX = tmpX;
			posY = tmpY;
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> totalRotate;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < (min(N, M) / 2); i++)
	{
		rotateBoard(i);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
