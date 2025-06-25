#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 3000000;

struct node {
	int nodeNum;
	int weight;

	bool operator<(const node& other) const {
		return weight > other.weight;
	}
};
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int v, e; cin >> v >> e;
	int start; cin >> start;

	vector<vector<node>> graph(v + 1);
	for (int i = 0; i < e; i++) {
		int s, e, w; cin >> s >> e >> w;
		graph[s].push_back({ e, w });
	}

	vector<bool> visited(v + 1);
	vector<int> dist(v + 1, INF);
	dist[start] = 0;
	
	priority_queue<node> q;
	// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	q.push({ start, 0 });
	while (!q.empty()) {
		node cur = q.top(); q.pop();
		if (visited[cur.nodeNum]) continue;
		visited[cur.nodeNum] = true;

		for (auto& nxt : graph[cur.nodeNum]) {
			if (dist[nxt.nodeNum] > dist[cur.nodeNum] + nxt.weight) {
				dist[nxt.nodeNum] = dist[cur.nodeNum] + nxt.weight;
				q.push({ nxt.nodeNum, dist[nxt.nodeNum] });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if(dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}
