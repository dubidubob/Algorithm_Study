#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> listA;
	vector<int> graph;
	listA.resize(N + 1);
	graph.resize(N+1);

	int front, back;
	for (int i = 0; i < M; i++) 
	{
		cin >> front >> back;
		listA[front].push_back(back);
		graph[back]++;
	}

	queue<int> queue;
	// 교재 코드 : 0인 걸 모두 큐에 넣어두고, 하나씩 차수를 뺀다. queue가 empty 할 때까지.

	for (int i = 1; i <= N; i++) {
		if (graph[i] == 0)
			queue.push(i);
	}

	while (!queue.empty()) {
		int now = queue.front(); //pop이 아니라 front!
		queue.pop();
		cout << now << " ";
		for(int next : listA[now])
		{
			graph[next]--;
			if (graph[next] == 0)
				queue.push(next);
		}
	}
		
	return 0;
}