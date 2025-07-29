#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000001;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	// N, M
	int n, m; cin >> n >> m;

	// vector에 담고, 최소값 도출
	vector<int> attraction(m + 1);
	int minT = MAX;
	for (int i = 1; i <= m; i++) {
		cin >> attraction[i];
		minT = min(attraction[i], minT);
	}

	if (n <= m) {
		cout << n;
		return 0;
	}
	// 0부터 m*min 중 이분탐색
	long long front = 1;
	long long back = (long long)minT * n;
	long long mid;
	long long resultT = 0;
	while (front <= back) {
		mid = (front + back) / 2;
		// 각 루프마다 모두 나눈 게 m보다 같거나 크다면 다음
		long long sum = m;
		for (int i = 1; i <= m; i++) {
			sum += (mid/attraction[i]);
			if (sum > n) {
				break;
			}
		}
		
		if (sum>=n) { // 더 작은 값 없는지 확인
			resultT = mid;
			back = mid - 1;
		}
		else if (sum < n) {
			front = mid+1;
		}
	}

	long long servedBefore = m;
	for (int i = 1; i <= m; i++) {
		servedBefore += (resultT - 1) / attraction[i];
	}
	long long remain = n - servedBefore;

	for (int i = 1; i <= m; i++) {
		if (resultT % attraction[i] == 0) {
			if (--remain == 0) {
				cout << i;
				break;
			}
		}
	}

	return 0;
}

