#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> arr(n);
	int idx = 0;
	arr[idx] = MAX;

	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;

		if (arr[idx] < cur) {
			arr[++idx] = cur;
			continue;
		}
			
		int front, end;
		front = 0; end = idx + 1;
		while (front < end) {
			int mid = (front + end) / 2;
			if (arr[mid] >= cur)
				end = mid;
			else
				front = mid + 1;
		}
		arr[end] = cur;

		/*cout << "\n cur : " << cur << " - ";
		for (int j = 0; j <= idx; j++) {
			cout << arr[j] <<" ";
		}*/
	}

	cout << idx+1;
	
	return 0;
}