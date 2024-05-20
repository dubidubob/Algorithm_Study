/*
대체 왜!!!! 다 줬잖아!! 다 줬잖아!!!!!!!!!

1. #include <algorithm> //sort를 가지려면 필요
2.
vector<bool> visited;
vector<vector<int>> graph;
이거 static 선언하든가 & 참조 형식으로 바꾸기! 아니면 복사된다~!
3. fill(visited.begin(), visited.end(), false); //방문 배열 초기화
4. while (!BFSqueue.empty()){ //while문 추가!!!
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort를 가지려면 필요
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int node, edge, start;

void DFS(int node);
void BFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge >> start;
	visited.resize(node + 1, false);
	graph.resize(node + 1);

	for (int i = 0; i < edge; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 1; i <= node; i++) {
		sort(graph[i].begin(), graph[i].end());//작은 순으로 뱉어라~!
	}

	DFS(start);
	cout << "\n";
	fill(visited.begin(), visited.end(), false); //방문 배열 초기화
	BFS(start);

	return 0;
}

void DFS(int node) {
	cout << node << " ";

	visited[node] = true;
	//cout << "\nvisited[" << node << "] = " << (bool)visited[node];
	for (int i : graph[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int node) {
	queue <int> BFSqueue;
	BFSqueue.push(node);
	visited[node] = true;

	while (!BFSqueue.empty()) { //while문 추가!!!
		int now = BFSqueue.front();
		BFSqueue.pop();
		cout << now << " ";

		for (int i : graph[now]) {
			if (!visited[i]) {
				visited[i] = true;
				BFSqueue.push(i);
			}
		}
	}
}
