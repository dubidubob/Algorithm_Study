/*
N ��� �� ��� 5���� ����Ǿ� �ִ� ���Ͽ��� �����ϴ��� ã�� ����

��� �� N(2000)
���� �� M(2000)

1. ��������Ʈ�� ���� ���� ����
2. DFS ����
	�� ��� Ÿ�� �� ��, ���� ���� ��ȯ
	�߿�. count �Լ��� ���� 1 ����� ������ ������Ʈ 
		count == 5 �� �� 1 ��� �� return
		�ƴ� �� continue, �������� 0 ��� �� return

��������Ʈ ���� ���!

*/

#include <iostream>
#include <vector>
using namespace std;

void main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//��������Ʈ �����ϴ� ��!
	vector<vector <int>> friends;
	vector<bool> visited;
	int N; //ģ��, ��� ����
	int M; //ģ�� ����, ���� ����

	cin >> N >> M;

	friends.resize(N + 1);
	visited.resize(N + 1);
	//��������Ʈ�� ���� �ޱ�
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		friends[start].push_back(end);
		friends[end].push_back(start);
	}
}