#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	// 인접리스트
	int h, w;
	cin >> h >> w;
	
	vector<vector<bool>> graph(h, vector<bool>(w, false));

	for (int i = 0; i < w; i++)
	{
		int height;
		cin >> height;

		for (int j = 0; j < height; j++)
			graph[j][i] = true;
	}

	int sum = 0;
	for (int i = 0; i < h; i++)
	{
		// 빗물은 벽 사이에 있어야 함
		// 카운트를 하고, 벽을 만날 때 최종적으로 더하기
		bool isRain = false;
		int cnt = 0;
		int isWall = 0;
		for (int j = 0; j < w; j++)
		{
			if (isWall == 0 && graph[i][j])
				isWall = 1;
			else if (isWall >= 1 && !graph[i][j])
			{
				cnt++;
				if(isWall == 1)
					isWall = 2;
			}
			else if (isWall == 2 && graph[i][j])
			{
				sum += cnt;
				cnt = 0;
				isRain = true;
				isWall = 1;
			}
		}

		// 만약 해당 row에 더해지는 게 없다면, 끝내기
		if (sum != 0 && !isRain)
			break;
	}
	
	cout << sum;
	
	return 0;
}
