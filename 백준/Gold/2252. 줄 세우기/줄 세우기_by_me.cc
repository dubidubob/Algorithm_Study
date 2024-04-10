#include <iostream>
#include <vector>
//#include <queue>
using namespace std;

/*
! main()은 무조건 int를 반환!
! queue 쓸 필요 없었음!
! push back vs emplace back
push back : 객체를 삽입하기 위해-> 똑같은 임시 객체를 하나 더 만들어서 여기에 값을 복사한 다음 벡터에 삽입
-> 삽입 후 임시 객체 파괴 : 잠깐 쓰고 버릴 메모리를 굳이 할당해줘야 한다.
	메모리 할당 X 데이터 삽입 Only / 인자값과 똑같은 임시 객체를 하나 더 만들어서 인자값으로 받은 값을 복사한다.
	벡터에 그 임시 객체를 추가, 

emplace back : 가변인자 템플릿을 사용, 삽입하려는 자료형에 따라 함수 내에서 삽입을 위한 객체를 자체 생성할 수 있다. 
-> 메모리 할당을 하는 동시에 값을 삽입

push back: capacity > element number reserve(1) capacity==element number reserve(capacity()*2)
https://www.youtube.com/watch?v=iba0YkOn4zw
https://www.youtube.com/watch?v=jKS9dSHkAZY

! resize 관련
listA.resize(N + 1, vector<int>(initialSize));
이렇게 미리 사이즈 결정할 수 있다.

* N 명, M 비교
* 
* front, back 
* 오는 족족 
인접리스트 M 만들고 
진입 차수 배열 업데이트

진입 차수 0부터(사이클이 없으니까) : 한 바퀴 돌면서, 진입 차수 0인 게 N번 되어야 함
인접리스트 M child 보고
진입 차수 배열 --
진입 차수 index queue에 넣기
*/
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

	//queue<int> queue;
	// 교재 코드 : 0인 걸 모두 넣어두고, 나머지를 

	int count = 0;//큐에 총 N가 추가되면, 종료
	for (int i = 1; count != N; i++) {
		if (graph[i] == 0) 
		{
			graph[i] = -1; //이미 추가했다는 표시
			cout << i << " ";//해당 인덱스 프린트

			for (int next : listA[i])
				graph[next]--; // 연결된 진입 차수 빼기
			count++;
		}
		if (i == N) i = i % N;// 한 바퀴 돌고 또 돌 수 있으니.
	}
	return 0;
}
