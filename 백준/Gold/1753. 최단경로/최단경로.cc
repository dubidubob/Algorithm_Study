#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int V, E, K;
vector<pair<int,int>> v[20010];//그래프
int d[20010];

void solution() {// 최단 경로 찾는 거
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,K });
    d[K] = 0;

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;

        pq.pop();

        if (d[current] < distance) continue;

        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i].first;
            int next_distance = distance + v[current][i].second;

            if (next_distance < d[next]) {
                d[next] = next_distance;
                pq.push({ -d[next],next });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}

int main() {
    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }

    for (int i = 1; i <= V; i++) {
        d[i] = INF;
    }

    solution();

    return 0;
}