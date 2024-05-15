/*
DFS : 탐색
여러 경우의 수를 출력해야한다면 
1. 가지치기
2. 소수 판별은? 에라토스테네스의 체? or 단순한 소수 판별 함수 사용
-N자릿수 소수 a: 2, 3, 5, 7, 시작을 이 경우만
-N-1자릿수 : 짝수는 제외

수도 코드

DFS : 각 노드에서 소수를 전부 내보내는 메소드
isPrimeNum : 소수 판별 메소드
main : 2 3 5 7마다 해당 소수 뱉기
*/

#include <iostream>
using namespace std;

void DFS(int number, int jarisu); //인접리스트에서 소수인 수 cout
bool isPrime(int num); //해당 숫자가 소수인지 판별

static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

void DFS(int number, int jarisu)
{
	if (jarisu == N)
	{
		if (isPrime(number)) 
		{
			cout << number << "\n";
		}
		return;
		
	}

	//각 자릿수마다
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0)//짝수면 무조건 패스
			continue; 
		if (isPrime(number * 10 + i))//이번 수가 소수라면,
		{
			DFS(number * 10 + i, jarisu + 1);//다음 자리수가 소수인지 검사해라
		}
	}
}

bool isPrime(int number)
{
	for (int i = 2; i <= (number / 2); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}