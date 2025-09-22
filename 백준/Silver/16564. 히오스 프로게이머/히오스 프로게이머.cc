#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	vector<ll> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	ll delta, cnt = 1, prev = arr[0], result = arr[0];

	for (int i = 0; i < n-1; i++)
	{
		delta = arr[i + 1] - arr[i];
		if (k > delta * cnt)
		{
			k -= delta * cnt;
			prev += delta;
			cnt++;
		}
		else
		{
			result = prev + (k / cnt);
			k = 0;
			break;
		}
	}

	if (k != 0)
	{
		result = prev + k / cnt;
	}

	cout << result;
	return 0;
}