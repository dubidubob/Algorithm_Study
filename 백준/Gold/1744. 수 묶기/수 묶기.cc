#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> plus;
	vector<int> minus;
	int ones = 0;
	int zeros = 0;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 1) ones++;
		else if (tmp == 0) zeros++;
		else if (tmp < 0) minus.push_back(tmp);
		else if (tmp > 0) plus.push_back(tmp);
	}

	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	int sum = 0;
	for (int i = plus.size()-1; i > 0; i -= 2)
	{
		sum += plus[i] * plus[i - 1];
	}
	if (plus.size() % 2 == 1)
		sum += plus[0];

	for (int i = 0; minus.size()!=0 && i < minus.size() - 1; i += 2)
	{
		sum += minus[i] * minus[i + 1];
	}
	if (minus.size() % 2 == 1 && zeros == 0)
		sum += minus[minus.size() - 1];

	sum += ones;

	cout << sum;

	return 0;
}
