/*
오해 : N 노드 중 노드 5개가 연결되어 있는 유니온이 존재하는지 찾는 문제
이게 아님!
N 노드에서 끝까지 갔을 때 5번 끝까지 갈 수 있는지 찾는 문제

노드 수 N(2000)
엣지 수 M(2000)

O(V+E): 노드 최대 범위: 2000 O(V+E)=O(4000) 각 노드에 대해서 2000*4000=8000000
->제한 시간 내에 가능(2초 2억회까지 가능)
1. 인접리스트로 관계 전부 삽입
2. DFS 실행
	각 노드 타고 들어간 뒤, 다음 노드로 전환
	중요. count 함수로 관계 1 깊어질 때마다 업데이트 
		count == 5 일 시 1 출력 후 return
		아닐 시 continue, 마지막에 0 출력 후 return

인접리스트 구현 방법!

재귀함수의 return 값
*/

#include <iostream>
#include <vector>
using namespace std;


//isArrive의 포인터 값
void DFS(vector<vector<int>>& friends, vector<bool>& visited, int N, int depth, bool& isArrive);
int main() //main must return int
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector <int>> friends;
	vector<bool> visited;
	bool isArrive; //depth의 끝까지 갔는지

	int N; //친구, 노드 개수
	int M; //친구 관계, 엣지 개수

	cin >> N >> M;
	isArrive = false;
	friends.resize(N + 1);
	visited.resize(N + 1, false); //false로 초기화

	//인접리스트로 관계 받기
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		friends[start].push_back(end);
		friends[end].push_back(start);
	}

	for (int i = 0; i < N; i++)
	{
		//해당 노드에서 쭉 타고 들어간 단계의 수
		DFS(friends, visited, i, 1, isArrive);
		if (isArrive)
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}

void DFS(vector<vector<int>>& friends, vector<bool>& visited, int N, int depth, bool& isArrive)
{
	if (depth == 5)
	{
		isArrive = true;
		return;
	}

	visited[N] = true;

	for (int i : friends[N])
	{
		if (!visited[i])
		{
			DFS(friends, visited, i, depth+1, isArrive);
		}
	}

	visited[N] = false;//depth로만 따지는 것이기 때문에 다시 없애야 한다.
}
/*
int main() //main must return int
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//인접리스트 구현하는 법!
	vector<vector <int>> friends;
	vector<bool> visited;
	int N; //친구, 노드 개수
	int M; //친구 관계, 엣지 개수
	int count; //친구 계산

	cin >> N >> M;

	friends.resize(N + 1);
	visited.resize(N + 1, false); //false로 초기화
	//인접리스트로 관계 받기
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		friends[start].push_back(end);
		friends[end].push_back(start);
	}

	for (int i = 0; i < N; i++)
	{
		count = 1;
		if (!visited[i])
		{
			count = DFS(friends, visited, i, count);//해당 노드에서 쭉 타고 들어간 단계의 수
			//cout << "이ㅑ야야" << count;
			if (count >= 5)
			{//5명이 있을 때
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}

int DFS(vector<vector<int>> friends, vector<bool> visited, int N, int count) 
{	
	if (visited[N])
	{
		//cout << "냐냐\n";
		return count;
	}

	visited[N] = true;

	for (int i : friends[N])
	{
		if (visited[i] == false)
		{
			if (count >= 5)
			{
				return count;
			}
			//cout << "요" << count << " " << i<<"\n";
			//if (count == 5)
			//{
			//	return count;//만약 5라면, 계산 멈추고 출력
			//}
			
			count = 1;//count 초기화
			count=DFS(friends, visited, i, count);
		}
	}
	
	return ++count; //이게 중요했음! 끝까지 다다랐을 때!
}*/