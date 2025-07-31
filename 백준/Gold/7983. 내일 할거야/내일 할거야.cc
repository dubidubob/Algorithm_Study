#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1000000001;

struct node {
	int dday;
	int cost;
	bool operator <(const node& other) const {
		return dday < other.dday;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;

	priority_queue<node> pq;
	for (int i = 0; i < n; i++) {
		int c, d; cin >> c >> d;
		pq.push({d, c});
	}

	int pointer = MAX;
	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();

		if (cur.dday <= pointer) {
			pointer = cur.dday;
			pointer -= cur.cost;
		}
		else {
			pointer -= cur.cost;
		}
	}

	cout << pointer;
	

	return 0;
}

