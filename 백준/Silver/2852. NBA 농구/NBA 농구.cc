/*
stoi, stof, stol, stod : string to int, float, long, double

비기고, 뒤집히는 시점만 잘 알면 된다.
01 : 10 처음
02 : 20 안뒤집힘
45 : 30 안뒤집힘
46 : 40 비김, 1의 승리, 46 : 40 - 01 : 10 = 45 : 30
47 : 50 뒤집힘, 2의 승리, 48 : 00 -47 : 50 = 00 : 10

마지막 : 48 : 00 - 21 : 10 

N번 동안 시간 받기
전 시간에서 빼기만 하면 됨!
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, team, min, sec, beforeS, total_1 = 0, total_2 = 0, score_1 = 0, score_2 = 0;
	string t;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> team >> t;
		min = stoi(t.substr(0, 2));
		sec = stoi(t.substr(3, 2));

		if (score_1 > score_2)
		{
			total_1 += (min * 60) + sec - beforeS;
		}
		else if (score_2 > score_1)
		{
			total_2 += (min * 60) + sec - beforeS;
		}
		if (team == 1) score_1++;
		else score_2++;
		beforeS = (min * 60) + sec;
	}

	if (score_1 > score_2) total_1+= (48 * 60) - beforeS;
	else if (score_2 > score_1) total_2 += (48 * 60) - beforeS;

	printf("%02d:%02d\n", total_1 / 60, total_1 % 60);
	printf("%02d:%02d\n", total_2 / 60, total_2 % 60);

	return 0;
}