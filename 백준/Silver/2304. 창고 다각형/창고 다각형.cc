#include <iostream>

using namespace std;
const int MAX = 1001;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;

	int arr[MAX] = {0};
	int left=N, right=0, middle =0, middleCost=0;
	for (int i = 0; i < N; i++)
	{
		int idx, cost;
		cin >> idx >> cost;
		arr[idx] = cost;

		left = left > idx ? idx : left;
		right = right < idx ? idx : right;
		if (middleCost < cost)
		{
			middleCost = cost;
			middle = idx;
		}
	}

	//cout << left << " " << right << " " << middle << " " << middleCost;
	int result = 0;
	int cur = 0;
	for (int i = left; i <= middle; i++)
	{
		if (cur < arr[i])
			cur = arr[i];
		result += cur;
	}

	cur = 0;
	for (int i = right; i > middle; i--)
	{
		if (cur < arr[i])
			cur = arr[i];
		result += cur;
	}

	cout << result;

	return 0;
}
