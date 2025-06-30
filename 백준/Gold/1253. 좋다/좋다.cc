#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) 
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        int front = 0, end = n - 1;
        while (front < end) {
            int sum = nums[front] + nums[end];
            if (front == i) front++;
            else if (end == i) end--;

            else if (sum == nums[i]) {
                count++;
                break;
            }
            else if (sum < nums[i]) {
                front++;
            }
            else if (sum > nums[i]) {
                end--;
            }
        }
    }

    cout << count; 
    return 0;
}
