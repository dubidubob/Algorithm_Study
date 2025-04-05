#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
//int[2]은 안 됨!
const vector<pair<int, int>> baseDir = {
	{ -1, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 }
};
constexpr int DirNum = 4;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int Row, Col;
	cin >> Row >> Col;

	int posX, posY, curDir;
	cin >> posX >> posY >> curDir;

	vector<vector<int>> room(Row, vector<int>(Col));
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			cin >> room[i][j];
		}
	}

	int cleanedRoom = 0;
	for (int i = 0; i < Row * Col; i++)
	{
		if (room[posX][posY] == 0)
		{
			//방 청소
			room[posX][posY] = 2;
			cleanedRoom++;
		}

		bool isNoRoom = true;
		for (int i = 1; i <= DirNum; i++)
		{
			int tmpX = posX + baseDir[(curDir - i + DirNum) % DirNum].first;
			int tmpY = posY + baseDir[(curDir - i + DirNum) % DirNum].second;
			if (0 < tmpX && tmpX < Row - 1 && 0 < tmpY && tmpY < Col - 1 && room[tmpX][tmpY] == 0)
			{
				posX = tmpX;
				posY = tmpY;
				curDir = (curDir - i + DirNum) % DirNum;
				isNoRoom = false;
				break;
			}
		}

		//주변에 방 없을 때
		if (isNoRoom)
		{
			int tmpX = posX - baseDir[curDir].first;
			int tmpY = posY - baseDir[curDir].second;
			if (0 < tmpX && tmpX < Row - 1 && 0 < tmpY && tmpY < Col - 1 && room[tmpX][tmpY] != 1)
			{
				posX = tmpX;
				posY = tmpY;
				continue;
			}
			else
				break;
		}
	}

	cout << cleanedRoom;

	return 0;
}