#include <iostream>
#include <vector>
using namespace std;

/*
n: 집합 개수+1
m: 입력으로 주어지는 연산의 개수
합집합: 0 a b - a, b 포함되어있는 집합끼리 합친다.
두 원소가 같은 집합에 포함되어 있는지 확인하는 연산: 1 a b

1 : yes , no
{0}{1}{2}{3}{4}{5}{6}{7}
{0}{1,3}{2}{4}{5}{6}{7}
No
{0}{1,3}{2}{4}{5}{6, 7}
No
{0}{1,3, 6,7}{2}{4}{5}
{0}{1,3, 6,7}{2, 4}{5}
{0}{1,3, 6,7}{2, 4}{5}
Yes
*/

static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int question, a, b;
		cin >> question >> a >> b;

		if (question == 0) {
			unionfunc(a, b);
		}
		else {
			if (checkSame(a, b))
				cout << "yes" << "\n";
			else
				cout << "no" << "\n";
		}
	}
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int find(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}

bool checkSame(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return true;
	return false;
}
