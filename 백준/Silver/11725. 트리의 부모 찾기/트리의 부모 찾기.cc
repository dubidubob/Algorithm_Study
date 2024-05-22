/*
1-6-3-5
 -4-2
   -7

   함수
   삽입할 때
   1이 있는 쌍을 먼저 넣는다
   다음 1에 달려있는 쌍을...
   vector잖아? 
   1. 부모가 있으면 없는 애가 자식
   2. 1은 부모가 1이다

   print

   자료형
   1. 부모 표시용 배열
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void BFS(int now) {
	queue<int> Q;
	Q.push(now);
	visited[now] = 1;

	while (!Q.empty()) {
		now = Q.front();
		//cout << "asdf" << now;
		Q.pop();
		
		for (int i : graph[now]) {
			if (visited[i]==0) {//자식 노드가 방문 안 됐을 때 큐에 넣기
				visited[i]=now;		
				//cout << "\n"<<i << " " << visited[i];
				Q.push(i);
			}
		}
	}
}

void printBFS() {
	for (int i = 2; i < graph.size(); i++) {
		cout << visited[i] << "\n";
	}
}

int main() {
	int N;

	cin >> N;
	graph.resize(N + 1);
	visited.resize(N + 1, 0);

	for (int i = 1; i < N; i++) {//N-1번 동안 그래프 삽입
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	BFS(1);

	printBFS();

	return 0;
}

/*
void recordParent(vector<int>& parentArr, int a, int b) {
	
	if (parentArr[a] != 0) {//a에게 부모가 있다면, b의 부모가 a
		parentArr[b] = a;
		//cout << b << "의 부모"<< parentArr[b];
	}
	else if (parentArr[b] != 0) {
		parentArr[a] = b;
		//cout << a << "의 부모" << parentArr[a];
	}
	else if (parentArr[a] && parentArr[b] == 0) {//둘 다 부모가 없다면

	}
	return;
	//만약 a도, b도 아직 부모가 없다면?!
	//ㄴ이 문제 때문에 안 되는 거임
}

int main() {
	int N; //노드 개수
	vector<int> parentArr; //부모 표시용

	cin >> N;
	parentArr.resize(N + 1, 0);

	parentArr[1] = 1;

	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;

		recordParent(parentArr, a, b);
	}

	for (int i = 2; i < parentArr.size(); i++) {//배열 범위! 2부터 7이니까(size는 총 N+1 : 8개)
		cout << parentArr[i] << "\n";
	}

	return 0;
}
*/