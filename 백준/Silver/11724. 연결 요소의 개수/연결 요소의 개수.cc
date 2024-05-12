#include <iostream>
#include <vector>
using namespace std;
/*
* 이거 유니온 파인드 아이가
* 노드 최대 개수 1000 - > N^2 이하의 알고리즘 모두 사용 가능
*/


static vector<vector <int>> A;
static vector<bool> visited;

void DFS(int v);

int main()
{
	int n=0, m=0 ; //정점 개수와 간선의 개수
	cin >> n >> m;
	A.resize(n + 1); //정점 개수로 인접리스트 resize, 초기화
	visited = vector<bool>(n + 1, false); //벡터 초기화

	for (int i = 0; i < m; i++)
	{
		int s, e;//start end
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);//무방향 그래프, 양쪽 다 저장
	}

	int count = 0;

	for(int i=1;i<n+1;i++)
	{ 
		if (!visited[i])
		{
			count++;
			DFS(i); //유니온 파인드 함
		}
	}
	cout << count << '\n';
	return 0;
}

void DFS(int v) {
	if (visited[v])
		return;

	visited[v] = true;

	for (int i : A[v])
	{
		if (visited[i] == false)
			DFS(i);
	}
}