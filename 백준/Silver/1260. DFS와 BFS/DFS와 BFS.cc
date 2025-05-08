#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur)
{
	cout << cur << " ";
	visited[cur] = true;

	for (int child : graph[cur])
	{
		if (!visited[child])
		{
			dfs(child);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int v, e, s;
	cin >> v >> e >> s;

	graph.resize(v+1);
	for (int i = 0; i < e; i++)
	{
		int f, l;
		cin >> f >> l;

		graph[f].push_back(l);
		graph[l].push_back(f);
	}

	for (int i = 1; i <= v; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	visited.resize(v+1, false);
	dfs(s);

	visited.clear();
	visited.resize(v+1, false);
	cout << "\n";

	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (visited[cur])
			continue;
		visited[cur] = true;
		cout << cur <<" ";

		for (int child : graph[cur])
		{
			if (visited[child])
				continue;
			q.push(child);
		}
	}

	return 0;
}
