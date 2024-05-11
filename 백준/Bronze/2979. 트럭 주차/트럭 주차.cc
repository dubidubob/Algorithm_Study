#include <iostream>
 
using namespace std;
 
int arr[105];
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = 0; i < 3; i++){
		int start = 0, end = 0;
		cin >> start >> end;
		for(int j = start; j < end; j++){
			arr[j]++;
		}
	}
	
	int sum = 0;
	for(int i = 0; i < 105; i ++){
		if(arr[i] == 1)
			sum += arr[i] * a;
		else if(arr[i] == 2)
			sum += arr[i] * b;
		else if(arr[i] == 3)
			sum += arr[i] * c;
	}
	
	cout << sum;
}

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
