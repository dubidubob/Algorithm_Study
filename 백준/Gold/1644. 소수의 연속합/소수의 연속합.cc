#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

void isPrime(int num) {

	vector<bool> check;
	check.resize(num + 1, true);

	for (int i = 2; i <= sqrt(num); i++) {
		if (check[i]) {
			for (int j = i + i; j <= num; j += i) {
				check[j] = false;
			}
		}
	}
	//int k = 0;
	for (int i = 2; i <= num; i++) {
		if (check[i]) {
			primes.push_back(i);
			
			//primes[k] = i; //크기 지정을 안 했잖아!, 하면 안 됨
			//k++;
			//cout << " \nprimes k" << k << " = " << i;
		}
	}

	primes.push_back(num+1);

	//for (int prime : primes) {
	//	cout << prime << " ";
	//}
	//cout << "************************";
}

int main() {
	int N;
	cin >> N;

	int sub = 0;
	int add = 0;
	int sum = 0;
	int count = 0;

	isPrime(N);

	while (add<primes.size()) {//add가 소수 벡터의 끝까지 가기까지
		//이러면 41(소수)의 경우, 마지막 경우의 수인 자기자신: +41 = 41이 count가 안 돼
		if (sum > N) {
			sum -= primes[sub++];
			//cout << "\n -sub: " << primes[sub - 1] << " sum: " << sum;
		}
		else if (sum < N) {
			sum += primes[add++];
			//cout << "\n +add: " << primes[add - 1] << " sum: " << sum;
		}
		else {//sum == N
			//cout << " sum : +++++++" << sum;
			count++;
			sum += primes[add++];
		}
	}

	//cout << "\n count: "<<count;
	cout << count;
}
/*
****************************************************
* 아래 뭔소리임 걍 니가 문제를 존나 못 알아처먹은 거잖아아아
*****************************************************
DP 문제다
n^2

arr
2  3  4  5  6  7  8  9 10 11 12
1  1  0  1	1  1  1  1

소수 리스트
2 3 5 7
2 3 5 7 11


2. 큰 소수 빼고 나머지 DP의 횟수 더하기
3. 반복 : 큰 소수가 나머지보다 작아지면 끔
1. 소수입니까 ? ->리스트 넣기
4. 다음으로 이동

1. 소수 전체 배열 (체)
2. largerPrime 인덱스 0으로 초기화
	1. largerPrime이 현재 i보다 작으면 ++
3. largerPrime-1 ~ remain(i- nextPrime)까지 해당 ways[remain] 더하기
4. N까지 반복

int main() {
	int N;
	vector<int> ways;

	//초기화
	cin >> N;
	primes.resize(N + 1);
	ways.resize(N + 1);

	ways[0] = 0;
	ways[1] = 0;
	ways[2] = 1;
	ways[3] = 1;

	//에라토스테네스의 체로 모든 소수를 담은 배열
	isPrime(N);
	primes.push_back(N + 1);//맨 마지막에 N+1

	int largerPrime = 0;//이 인덱스의 소수보다 작을 때는 전 거부터 써라.

	for (int i = 4; i <= N; i++) {
		while (i > primes[largerPrime]) {
			largerPrime++;
			cout << "\n현재 i: "<<i<<" largerPrime: "<<primes[largerPrime];
		}

		int nextPrime = largerPrime - 1;
		int remain = i - primes[nextPrime];

		while (remain < primes[nextPrime]) {
			ways[i] += ways[remain];
			nextPrime--;
			remain = i - primes[nextPrime];
			cout << "\n현재 ways: " << i << " = " << ways[i]<<" remain "<< remain<< " nextprime "<<primes[nextPrime];
		}
	}
	cout << ways[N];

	return 0;
}
*/

