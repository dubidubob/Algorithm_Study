#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, c;
	cin >> n >> c;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int front, end;
	front = 1; end = arr[arr.size() - 1] - arr[0] + 1;

	while (front < end) {
		int mid = (front + end) / 2;
		int cnt = 1;
		int prev = arr[0];
		// cout << "\n"<< mid <<" : " << prev << " ";
		for (int i : arr) {
			if ((i - prev) >= mid) {
				cnt++;
				prev = i;
				// cout << prev << " ";
			}
			if (cnt >= c)
				break;
		}

		if (cnt >= c) {
			front = mid + 1;
		}
		else {
			end = mid;
		}
	}
	// cout << "\n 정답 : "<< front - 1;
	cout << front - 1;

	return 0;
}