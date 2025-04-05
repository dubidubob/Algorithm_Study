#include <iostream>
#include <vector>

using namespace std;

int chosenChickCnt;

int N;
int answer;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int hToC[101][14];

int minDist(vector<int> chicks)
{
	int sum = 0;
	for (int hIdx = 0; hIdx < houses.size(); hIdx++)
	{
		const auto& house = houses[hIdx];
		int minimum = 2 * N;
		for (int chick : chicks)
		{
			//cout << "조합 인덱스 h to c : "<<hIdx<< " : " << chick << "의 거리" << hToC[hIdx][chick] << "\n";
			minimum = min(hToC[hIdx][chick], minimum);
		}
		//cout << "minimum " << minimum << "\n";
		sum += minimum;
	}
	//cout << "sum : " << sum << "\n";
	return sum;
}

void combination(int depth, int next, vector<int> chicks)
{
	if (depth == chosenChickCnt)
	{
		answer = min(minDist(chicks), answer);
		//cout << "answer : " << answer << "\n";
		return;
	}

	for (int i = next; i < chickens.size(); i++)
	{
		vector<int> newChicks = chicks;
		newChicks.push_back(i);
		
		combination(depth + 1, i + 1, newChicks);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> chosenChickCnt;

	int board[51][51];
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= N; col++)
		{
			cin >> board[row][col];
			if (board[row][col] == 1)
				houses.push_back({ row, col });//100 이하 개

			else if (board[row][col] == 2)
				chickens.push_back({ row, col });//13 이하개
		}
	}

	for (int hIdx = 0; hIdx<houses.size(); hIdx++)
	{
		const auto& house = houses[hIdx];
		for (int cIdx =0; cIdx < chickens.size();  cIdx++)
		{
			const auto& chicken = chickens[cIdx];
			int dist = abs(house.first - chicken.first) + abs(house.second - chicken.second);
			hToC[hIdx][cIdx] = dist;
		}
	}

	answer = (2 * N)*(2* N);
	//nCr
	vector<int> chicks;
	combination(0, 0, chicks);
	cout << answer;

	return 0;
}
