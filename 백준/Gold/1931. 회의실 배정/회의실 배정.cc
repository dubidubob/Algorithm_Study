#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 100000;

struct node {
	int head;
	int tail;

	bool operator >(const node& others) const {
		if (head == others.head)
			return tail > others.tail;
		return head > others.head;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;

	priority_queue<node, vector<node>, greater<node>> q;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		node cur = { a, b };
		q.push(cur);
	}

	stack<node> st;
	while (!q.empty()) {
		node nxt = q.top(); q.pop();
		
		if (st.empty()) {
			st.push(nxt);
			continue;
		}

		node cur = st.top();
		if (nxt.head >= cur.tail)
			st.push(nxt);
		else if(nxt.tail<cur.tail){
			st.pop();
			st.push(nxt);
		}
	}

	int  result = st.size();
	cout << result;

	return 0;
}
