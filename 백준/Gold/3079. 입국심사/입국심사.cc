#include <iostream>
#include <vector>
using namespace std;
const long long MAX = 1000000000;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;

	int minNum = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		minNum = max(minNum, arr[i]);
	}

	long long front, end;
	front = 0; end = (long long)minNum * m;
	long long result = end;
	// 최소 -> 
	while (front <= end) {
		long long mid = front + (end - front) / 2;
		long long sum = 0;
		for (int i : arr) {
			sum += mid / i;
			if (sum >= m) break;
		}
			
		if (sum >= m) {
			result = mid;
			end = mid-1;
		}
		else {
			front = mid + 1;
		}
	}
	cout << result;

	return 0;
}