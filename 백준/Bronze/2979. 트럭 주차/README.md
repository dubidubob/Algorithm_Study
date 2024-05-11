/* 이거 왜 안 될까...
#include <iostream>
#include <vector>
			using namespace std;

		int main()
		{
			//초기화 어떻게 하는지
			vector<int> carpark(105, 0);

			//각 차가 들어오고 나가는 시간
			int i, j;
			//차 1대 2대 3대 별 주차값
			int coin1, coin2, coin3;
			//1대, 2대, 3대일 때 총 시간
			int count1 = 0, count2 = 0, count3 = 0;

			cin >> coin1 >> coin2 >> coin3;

			for (int l = 0; l < 3; l++)
			{
				cin >> i >> j;

				for (int k = i; k < j; k++)
				{
					carpark[k]++;
				}
			}

			//carpark.resize(j);

			int sum = 0;
			//if문 3개 이하면 if > switch
			for (int i = 0; i < j; i++)
			{
				if (carpark[i] == 1)
					sum += carpark[i] * coin1;
				else if (carpark[i] == 2)
					sum += carpark[i] * coin2;
				else if (carpark[i] == 3)
					sum += carpark[i] * coin3;
			}
			cout << sum;

			return 0;
		}
*/

# [Bronze II] 트럭 주차 - 2979 

[문제 링크](https://www.acmicpc.net/problem/2979) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2024년 5월 12일 01:04:36

### 문제 설명

<p>상근이는 트럭을 총 세 대 가지고 있다. 오늘은 트럭을 주차하는데 비용이 얼마나 필요한지 알아보려고 한다.</p>

<p>상근이가 이용하는 주차장은 주차하는 트럭의 수에 따라서 주차 요금을 할인해 준다.</p>

<p>트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 두 대를 주차할 때는 1분에 한 대당 B원, 세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.</p>

<p>A, B, C가 주어지고, 상근이의 트럭이 주차장에 주차된 시간이 주어졌을 때, 주차 요금으로 얼마를 내야 하는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 문제에서 설명한 주차 요금 A, B, C가 주어진다. (1 ≤ C ≤ B ≤ A ≤ 100)</p>

<p>다음 세 개 줄에는 두 정수가 주어진다. 이 정수는 상근이가 가지고 있는 트럭이 주차장에 도착한 시간과 주차장에서 떠난 시간이다. 도착한 시간은 항상 떠난 시간보다 앞선다. 입력으로 주어지는 시간은 1과 100사이 이다.</p>

### 출력 

 <p>첫째 줄에 상근이가 내야하는 주차 요금을 출력한다.</p>

