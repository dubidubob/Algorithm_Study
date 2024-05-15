/*
N 노드 중 노드 5개가 연결되어 있는 유니온이 존재하는지 찾는 문제

노드 수 N(2000)
엣지 수 M(2000)

1. 인접리스트로 관계 전부 삽입
2. DFS 실행
	각 노드 타고 들어간 뒤, 다음 노드로 전환
	중요. count 함수로 관계 1 깊어질 때마다 업데이트 
		count == 5 일 시 1 출력 후 return
		아닐 시 continue, 마지막에 0 출력 후 return

인접리스트 구현 방법!

*/

#include <iostream>
#include <vector>
using namespace std;

void main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//인접리스트 구현하는 법!
	vector<vector <int>> friends;
	vector<bool> visited;
	int N; //친구, 노드 개수
	int M; //친구 관계, 엣지 개수

	cin >> N >> M;

	friends.resize(N + 1);
	visited.resize(N + 1);
	//인접리스트로 관계 받기
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		friends[start].push_back(end);
		friends[end].push_back(start);
	}
}