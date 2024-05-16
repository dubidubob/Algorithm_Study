#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> A, vector<bool> visited, int start);
void BFS(vector<vector<int>> A, vector<bool> visited, int start);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> A;
	vector<bool> visited;
	int N, M, start;
	cin >> N >> M >> start;

	A.resize(N + 1);
	
	//인접리스트에 모두 저장
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	visited.resize(N + 1, false);
	DFS(A, visited, start);
	visited.resize(N + 1, false);
	BFS(A, visited, start);
}

void DFS(vector<vector<int>> A, vector<bool> visited, int start)
{
	if (visited[start])
	{
		return;
	}

	visited[start] = true;
	cout << start<<" ";
	
	for (int i : A[start])
	{
		if (!visited[i])
		{
			DFS(A, visited, i);
		}
	}
}

void BFS(vector<vector<int>> A, vector<bool> visited, int start)
{
}