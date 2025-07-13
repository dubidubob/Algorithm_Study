#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
static bool visited[20001];
static bool isFalse[20001];
static bool isBipartite;

void dfs(int a)
{
	visited[a] = true;

	if (!isBipartite)
		return;

	for (int i = 0; i < graph[a].size(); i++)
	{
		int idx = graph[a][i];
		if (!visited[idx])
		{
			isFalse[idx] = !isFalse[a];
			dfs(idx);
		}
		else if (isFalse[idx] == isFalse[a])
				isBipartite = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;

	for (int j = 0; j < tc; j++)
	{
	
		int v, e;
		cin >> v >> e;

		graph.resize(v+1);
		isBipartite = true;

		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= v; i++)
		{
			if (!isBipartite)
				break;

			if(!visited[i])
				dfs(i);
		}
	
		string result = isBipartite ? "YES" : "NO";
		cout << result << "\n";

		for (int i = 0;i <= v; i++)
		{
			graph[i].clear();
			visited[i] = false;
			isFalse[i] = false;
		}
	}

	return 0;
}
