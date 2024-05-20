/*
유니온 파인드 아니야?
방향그래프
N 10,000 M 100,000
N개 노드, M개 엣지
BFS

1->3 (3이 1을 신뢰)
2->3
3->4
3->5

1->3->4(5)

1. 인접리스트로 모두 저장
parent child
1-1. visited를 int로 만들어서,
0으로 초기화
N번 루프:
	매 시작 때 parent는 child의 총 카운트를 가져온다
		DFS로 카운트
각 노드마다 얼마인지 return, 최고 기록이랑 해보고 같을 시 vector 뒤에 push back

vector[]

DFS
1. visited : 다녀갔는지 확인
2. hackCount : 각 노드가 parent일 때 얼마였는지 count
	만약 누군가의 child였다면 -1 표시로 뛰어넘기
3. graph : 단방향 그래프

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> hackCount;
vector<bool> visited;
int temp=0, maxCount=0;

void DFS(int node) {//해당 parent 해킹 가능 수 return
	visited[node] = true;

	for (int i :graph[node]) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(i);
			temp++;
		}
	}
}

int main() {
	int node, edge;

	cin >> node >> edge;
	graph.resize(node+1);
	hackCount.resize(node + 1, 0);

	for (int i = 0; i < edge; i++) {//인접리스트 만들었다
		int parent, child;
		cin >> child >> parent;
		graph[parent].push_back(child); //단방향 그래프
	}

	for (int i = 0; i < node; i++) {//DFS 실행, DFS는 부모의 최대 count 반환
		visited.resize(node + 1, false);

		DFS(graph[i]);
		hackCount[i] = temp;
		cout << "\nhackCount[] " << i << " = " << temp;
		if (temp > maxCount) {//최고
			maxCount = temp;
		}
	}

	for (int i = 0; i < node; i++) {
		if (hackCount[i] == maxCount) {
			cout << i << " ";
		}
	}
}
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> v[10001];
bool visit[10001];
int cnt = 0;
int mm = 0;
int result[10001];

void dfs(int n) {
	cnt++;

	for (int i = 0; i < v[n].size(); i++) {
		int nn = v[n][i];

		if (visit[nn]) continue;

		visit[nn] = true;
		dfs(nn);
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));

		cnt = 0;

		visit[i] = true;
		dfs(i);

		result[i] = cnt;
		mm = max(mm, cnt);
	}

	for (int i = 1; i <= N; i++) {
		if (result[i] == mm) {
			cout << i << " ";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	solution();

	return 0;
}
