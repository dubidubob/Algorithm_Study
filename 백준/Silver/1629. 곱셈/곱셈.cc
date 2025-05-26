#include <iostream>
using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    if (exp == 1) return base % mod;

    long long result = mod_pow(base, exp / 2, mod);
    result = (result * result) % mod;

    if (exp % 2 == 1)
        result = (result * base) % mod;

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << mod_pow(a, b, c) << "\n";

    return 0;
}
