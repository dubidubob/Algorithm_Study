#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct node {
    string w;
    int cost;
    bool operator<(const node& other) const {
        return cost < other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, int> mapp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mapp[s]++; 
    }

    priority_queue<node> pq;
    for (auto const& pair : mapp) {
        pq.push({ pair.first, pair.second }); 
    }

    int key;
    cin >> key;
    bool isOn = false;
    while (!pq.empty()) {
        node candi = pq.top();
        pq.pop();

        int cnt = 0;
        for (char ch : candi.w) {
            if (ch == '0') {
                cnt++;
            }
        }

        if (key < cnt || (key - cnt) % 2 == 1) {
            continue;
        }

        cout << candi.cost;
        isOn = true;
        break;
    }

    if (!isOn) cout << 0;
    return 0;
}