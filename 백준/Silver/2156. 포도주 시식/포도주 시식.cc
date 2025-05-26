#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> results;
vector<bool> visited;
int n;

void print(int level) {
    cout << "\n레벨 : "<<level<<"\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << results[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << visited[i] << " ";
    }
    cout << "\n";
}
void dp(int level) {
    if (level>n) {
        cout << results[level-1];
        return;
    }
    //2
    if (visited[level - 1]) {
        int sub1 = results[level - 1];
        int sub2 = nums[level] + results[level - 2];
        int sub3 = nums[level] + nums[level - 1] + results[level - 3];

        if (sub1 > sub2) {
            if (sub1 > sub3) {
                results[level] = sub1;
            }
            else {
                results[level] = sub3;
                visited[level] = true;
            }
        }
        else {
            if (sub2 > sub3) {
                results[level] = sub2;
            }
            else {
                results[level] = sub3;
                visited[level] = true;
            }
        }
    }
    else {
        int sub1 = results[level - 1] + nums[level];
        results[level] = sub1;
        visited[level] = true;
    }
    // print(level);
    dp(++level);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    nums.resize(n+1, 0);
    results.resize(n+1, 0);
    visited.resize(n+1, false);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    if (n == 1) {
        cout << nums[1];
    }
    else if (n == 2) {
        cout << nums[1] + nums[2];
    }
    else {
        results[1] = nums[1];
        results[2] = nums[1] + nums[2];
        visited[2] = true;
        dp(3);
    }

    return 0;
}
