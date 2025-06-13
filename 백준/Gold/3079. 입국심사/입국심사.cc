#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

using namespace std;
// const long long MAX = 1000000000; // 이 상수는 사용되지 않으므로 제거하거나 적절히 사용

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	long long m; // M이 10억까지 갈 수 있으므로 long long으로 선언
	cin >> n >> m;

	vector<long long> arr(n); // 심사 시간도 10^9까지이므로 long long으로 선언
	long long maxTime = 0; // 가장 오래 걸리는 심사 시간을 저장
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxTime = max(maxTime, arr[i]);
	}

	long long front, end;
	front = 0; // 최소 시간은 0 또는 1 (문제 조건에 따라)
	// 가장 오래 걸리는 심사대에서 m명이 모두 심사 받을 때의 시간을 end로 설정
	// long long으로 형변환하여 오버플로우 방지
	end = maxTime * m; 
    // 최소 1초는 걸리므로 front를 1로 시작하거나, end를 (long long)maxTime * m + 1로 잡는 것이 더 안전합니다.
    // 현재 코드에서는 front가 0에서 시작하고, 결국 m명을 처리할 수 있는 최소 시간을 찾으므로
    // end = maxTime * m; 으로 해도 됩니다.
    // 예를 들어, m=1이고 가장 빠른 심사대가 7초면, end는 7*1=7이 됩니다.
    // 그리고 front는 7로 수렴할 것입니다.

	long long result = end; // 가능한 최소 시간을 저장할 변수

	while (front <= end) { // front <= end 로 변경하는 것이 일반적인 이분 탐색 (정답을 찾을 때까지)
		long long mid = front + (end - front) / 2; // 오버플로우 방지
		
		long long sum = 0;
		for (long long time : arr) { // arr의 요소도 long long으로 받음
            // mid / time 연산 시, time이 0일 가능성은 없지만 (문제 조건 1 <= Tk),
            // sum이 long long 범위를 넘어설 수 있습니다. 그러나 문제에서 M이 10억이므로
            // sum += mid / time; 이 정상적으로 동작합니다.
			sum += mid / time; 
            // 만약 sum이 M을 훨씬 초과할 수 있는 경우, 
            // sum이 M에 도달하면 더 이상 더할 필요 없이 루프를 중단하여 최적화할 수 있습니다.
            if (sum >= m) break; // 불필요한 계산 방지 (최적화)
		}
		
		if (sum >= m) { // mid 시간으로 m명 이상을 처리할 수 있는 경우
			result = mid; // 현재 mid가 가능한 답이므로 저장
			end = mid - 1; // 더 짧은 시간으로도 가능한지 탐색
		}
		else { // mid 시간으로 m명을 처리할 수 없는 경우
			front = mid + 1; // 시간을 늘려야 함
		}
	}
	cout << result; // 최종적으로 찾은 최소 시간을 출력
	
	return 0;
}