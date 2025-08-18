#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	// 100000
	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> bigger; 
	priority_queue<int> smaller;
	
	int mid;	
	for (int i = 1; i <= n; i++)
	{
		// logN 시간에 중간값을 찾아라. 새 값만 비교하기에는 문제가 있다. 

		int tmp;
		cin >> tmp;

		if (i == 1)
		{
			mid = tmp;
		}
		else if (mid < tmp)
		{
			bigger.push(tmp);
			if (i % 2 == 1)
			{
				smaller.push(mid);
				mid = bigger.top();
				bigger.pop();
			}
		}
		else if (mid >= tmp)
		{
			smaller.push(tmp);
			if (i % 2 == 0)
			{
				bigger.push(mid);
				mid = smaller.top();
				smaller.pop();
			}
		}
		cout << mid << "\n";
	}

	return 0;
}
