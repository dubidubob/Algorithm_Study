#include <cstdio>

const int LM = 100000;
int arr[LM], dp[LM], n, ret;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d ", &arr[i]);

	ret = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ret = max(dp[i], ret);
	}

	printf("%d\n", ret);
	return 0;
}
