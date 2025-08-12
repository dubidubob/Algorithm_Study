#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result; cin >> result;

    sort(arr.begin(), arr.end());
    int front = 0, end = n - 1;
    int sum = 0;
    while (front < end)
    {
        int num = arr[front] + arr[end];
        if (num == result)
        {
            sum++;
            front++; end--;
        }
        else if (num > result)
        {
            end--;
        }
        else
        {
            front++;
        }
    }

    cout << sum;

    return 0;
}
