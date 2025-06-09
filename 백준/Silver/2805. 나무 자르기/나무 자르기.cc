#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long m;
    cin >> n >> m;

    vector<int> trees(n);
    int greatest = 0;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        greatest = max(greatest, trees[i]);
    }

    int front, end, mid;
    front = 0; 
    end = greatest;

    int result = 0;
    while (front <= end) {
        mid = (end + front) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i] > mid) {
                sum += trees[i] - mid;
            }
        }
        if (sum < m) { // 모자를 때는, end를 줄이고
            end = mid-1;
            // cout << "end \n" << result << " " << sum << "\n";
        }
        else { // 넘칠 때는 front를 올려. 
            result = mid;
            front = mid+1;
            // cout << "front \n" << result << " " << sum << "\n";
        }
    }
    
    cout << result;
    return 0;
}
