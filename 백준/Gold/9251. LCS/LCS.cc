#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	string mainW, subW;
	cin >> mainW >> subW;

	int answer = 0;
	vector<vector<int>> grid(subW.size()+1, vector<int>(mainW.size()+1));
	for (int i = 1; i < grid.size(); i++) {
		for (int j = 1; j < grid[0].size(); j++) {
			if (subW[i-1] == mainW[j-1]) {
				grid[i][j] = grid[i - 1][j - 1] + 1;
				answer = max(answer, grid[i][j]);
			}
			else {
				grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
			}
		}
	}

	cout <<  answer;
	

	return 0;
}
