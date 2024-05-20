/*
0. iterator로 해보기 <-> sorting을 통한 index 직접 지정
1. test case 
10 5 1
1 10
10 5
10 4
10 3
10 2
for (int i = 1; i <= node; i++)
<->
for (int i = 0; i < node; i++)
생각해보기
2. #include <algorithm> //sort를 가지려면 필요
3.
vector<bool> visited;
vector<vector<int>> graph;
이거 static 선언하든가 & 참조 형식으로 바꾸기! 아니면 복사된다~!
4. fill(visited.begin(), visited.end(), false); //방문 배열 초기화
5. while (!BFSqueue.empty()){ //while문 추가!!!
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
