#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
1. 최솟값 업데이트 해야한다.
2. 여러 점화식이 있다.
-> Dynamic programming
1 ~ N까지 벡터에다 채워야한다.
*/
int main()
{
	int n = 0;
	vector<int> D;

	//주어진 정수 n
	cin >> n;
	//vector 초기화
	D.resize(n + 1);

	D[1] = 0;

	for (int i = 2; i <= n;i++)
	{
		//1을 뺀다.
		D [i]= D[i - 1] + 1;
		if (i % 2 == 0) //2로 나눈다
			D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0)//3으로 나눈다
			D[i] = min(D[i], D[i / 3] + 1);
	}

	cout << D[n];
	return 0;
}