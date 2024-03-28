/*
1. for문 선언부에서는 여러 개의 값을 선언하려면 
for (int i = 0, a = 0, b = 0; i < M; i++) 이렇게.

2. 인풋을 배열 1부터 받으면 그냥 0번 인덱스는 비워놓고 똑같이 가기

3. //https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienullhttps://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
*/
#include <iostream>
#include <vector>
using namespace std;

void makeSumArray(vector<int>& sumArray, int N) {
	for (int i = 1, input = 0; i < N+1; i++)
	{
		cin >> input;
		sumArray[i] = sumArray[i - 1] + input;
	}
}

void printPartSum(vector<int>& sumArray, int M) {
	for (int i = 0, a = 0, b = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << sumArray[b] - sumArray[a - 1]<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M; //수의 개수, 횟수
	vector<int> sumArray(N+1, 0);

	makeSumArray(sumArray, N);
	printPartSum(sumArray, M);
}
