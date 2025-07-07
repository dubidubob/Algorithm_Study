#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> edges;
	
	for (int i = 0;i < m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}

	vector<long long> dist(n + 1, INF);
	dist[1] = 0;
	
	for (int i = 1; i < n;i++)
	{
		for (auto& edge : edges)
		{
			int u, v, cost;
			// tuple의 각 요소를 추출
			tie(u, v, cost) = edge;
			if (dist[u] != INF && dist[u] + cost < dist[v])
				dist[v] = dist[u] + cost;
		}
	}

	// 음수 사이클 검출: 한 번 더 완화해도 값이 갱신되면 음수 사이클 존재
	bool negativeCycle = false;
	for (auto& edge : edges) {
		int u, v, cost;
		tie(u, v, cost) = edge;
		if (dist[u] != INF && dist[u] + cost < dist[v]) {
			negativeCycle = true;
			break;
		}
	}

	if (negativeCycle)
		cout << -1 << "\n";
	else 
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == INF)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}

	return 0;
}
