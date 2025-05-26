#include <iostream>
using namespace std;

long long a, b, c;

long long dp(long long level) {
    if (level == 0) return 1;
    if (level == 1)
        return a % c;
   
    long long result = dp(level / 2);
    result = (result*result) % c;
    if (level % 2 == 1) {
        result = (result * a) % c;
    }

    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b >> c;

    cout << dp(b);
    
    return 0;
}
