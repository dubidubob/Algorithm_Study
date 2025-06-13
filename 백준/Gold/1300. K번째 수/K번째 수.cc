#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long n, k, result =0;
	cin >> n >> k;

	long start = 1, end = k;
	while (start <= end)
	{
		long sum = 0;
		long middle = (start + end) / 2;

		for (int i = 1; i <= n; i++)
			sum += min(middle / i, n);

		if(sum < k)
		{
			start = middle + 1;
		}
		else
		{
			result = middle;
			end = middle - 1;
		}
	}

	cout << result;
	
	return 0;
}