/* 
1. 컴파일 에러
for (int i = 0; i <= parentArray.size(); i++)
범위를 넘어선다!

2. 틀렸습니다.
-1로 하면 아직 안 합쳐진 건지, 한 집합의 부모인지 구별이 불가능하다. 
추가적인 조건을 더 달아줘야 하는데, 너무 복잡해진다.

3. 시간 초과
재귀함수를 넣지 않고, 집합 바뀔 때마다 O(N) 돌면서 전부 부모를 바꿔줘야 했음.

! 부모를 찾아야할 때는 재귀함수 쓰기!

*/
#include <iostream>
#include <vector>
using namespace std;

void UnionA(int a, int b, vector<int>& parentArray) {
	int parentA = parentArray[a];
	int parentB = parentArray[b];
	if (parentA == parentB) return;
	else if(parentA==a){//한쪽으로 전이
		for (int i = 0; i < parentArray.size(); i++) {
			if (parentArray[i] == parentB) {
				parentArray[i] = parentA;
			}
			
		}
	}
	else {
		for (int i = 0; i < parentArray.size(); i++) {
			if (parentArray[i] == parentA)
				parentArray[i] = parentB;
		}
	}
}

void SameA(int a, int b, vector<int>& parentArray) {
	if (parentArray[a] != -1 && parentArray[a] == parentArray[b]) cout << "yes" << "\n";
	else cout << "no" << "\n";
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M; //N개의 집합, M번의 연산
	cin >> N >> M;

	vector<int> parentArray(N + 1, -1);
	for (int i = 0; i <= N; i++) { //배열 초기화
		parentArray[i] = i;
	}

	int type, a, b;
	for (int i = 0; i < M; i++) 
	{
		cin >> type >> a >> b;
		switch (type)
		{
		case 0:UnionA(a, b, parentArray); break;
		case 1:SameA(a, b, parentArray); break;
		}
	}
	return 0;
}
