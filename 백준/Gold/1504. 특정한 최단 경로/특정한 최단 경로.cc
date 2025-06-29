#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long INF = 1e9 + 7;

struct node {
    int idx;
    long long weight;
    bool operator<(const node& other) const {
        return weight > other.weight;
    }
};

vector<vector<node>> graph;

vector<long long> dijkstra(int start, int size) {
    vector<long long> dist(size + 1, INF);
    priority_queue<node> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        node cur = pq.top(); pq.pop();

        if (dist[cur.idx] < cur.weight) continue; // 이미 더 짧은 거리로 방문됨

        for (auto& nxt : graph[cur.idx]) {
            if (dist[nxt.idx] > dist[cur.idx] + nxt.weight) {
                dist[nxt.idx] = dist[cur.idx] + nxt.weight;
                pq.push({nxt.idx, dist[nxt.idx]});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    graph.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    auto distFrom1 = dijkstra(1, v);
    auto distFromV1 = dijkstra(v1, v);
    auto distFromV2 = dijkstra(v2, v);

    long long path1 = distFrom1[v1] + distFromV1[v2] + distFromV2[v];
    long long path2 = distFrom1[v2] + distFromV2[v1] + distFromV1[v];

    long long answer = min(path1, path2);
    if (answer >= INF) cout << -1;
    else cout << answer;

    return 0;
}
