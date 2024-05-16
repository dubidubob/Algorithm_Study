/*
문제 해석 : N까지 올 때까지 몇 번의 10이 있었나? (5, 2 포함)
N: 1000, 000, 000(10억?)
DP 문제로 해결 불가능, logn으로 풀어야한다.
소인수분해
1 2 3 4 5 : 5가 1개 2가 3개 -> 10이 1개
1 2 3 4 5 6 7 8 9 10 -> 5가 1*2개 2가 2 22 222 6개 ->10이 2개
60 -> 5가 1*12 + 1*2 14개 2가 1*30 +2* ...
즉 5의 개수!

N 받고
N보다 작을 때까지 
1. 5의 제곱을 한다.
2. 해당 수로 N을 나눈 몫을 더한다.
*/

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int time; //횟수
	int N;
	int count;
	int fiveNsquare;
	cin >> time;

	for (int i = 0; i < time; i++)
	{
		cin >> N;
		count = 0;
		fiveNsquare = 5;

		while (fiveNsquare <= N)
		{
			count += N / fiveNsquare;
			fiveNsquare = fiveNsquare * 5;
		}

		cout << count<<"\n";
	}
}