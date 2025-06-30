#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int nodeA, nodeB;
    cin >> nodeA >> nodeB;

    vector<int> dist(MAX, MAX);
    vector<bool> visited(MAX);
    dist[nodeA] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ dist[nodeA], nodeA});
    while (!pq.empty()) {
        int curN  = pq.top().second;
        pq.pop();

        if (curN == nodeB) break;
        if (visited[curN]) continue;
        visited[curN] = true;

        if (curN - 1 >= 0 && dist[curN - 1] > dist[curN] + 1) {
            dist[curN - 1] = dist[curN] + 1;
            pq.push({ dist[curN - 1], curN - 1});
        }
        if (curN + 1 < MAX && dist[curN + 1] > dist[curN] + 1) {
            dist[curN + 1] = dist[curN] + 1;
            pq.push({ dist[curN + 1], curN + 1  });
        }
        if (curN * 2 < MAX && dist[curN * 2] > dist[curN]) {
            dist[curN * 2] = dist[curN];
            pq.push({ dist[curN * 2], curN*2 });
        }
    }

    cout << dist[nodeB];

    return 0;
}
