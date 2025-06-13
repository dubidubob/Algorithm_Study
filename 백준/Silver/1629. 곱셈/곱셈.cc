#include <iostream>
#include <vector>
using namespace std;

int dp(int a, int b, int c) {
	if (b == 1) 
		return a % c;
	
	long temp = dp(a, b / 2, c);
	if (b % 2 == 1) 
		return ((temp * temp)%c  * (a % c))%c;
		
	else 
		return (temp * temp) % c;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	cout << dp(a, b, c);
	
	return 0;
}