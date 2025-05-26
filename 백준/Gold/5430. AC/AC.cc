#include <iostream>
#include <string>
#include <deque>
using namespace std;

void func() {
    string word, arrays; 
    int n;
    cin >> word >> n >> arrays;
    
    string numStr;
    deque<int> dq;
    
    // 배열 파싱
    for (char ch : arrays) {
        if (isdigit(ch)) {
            numStr += ch;
        }
        else if (!numStr.empty()) {
            dq.push_back(stoi(numStr));
            numStr.clear();
        }
    }
    
    bool isRev = false;
    
    // 명령어 처리
    for (char ch : word) {
        if (ch == 'R') {
            isRev = !isRev;
        }
        else if (ch == 'D') {
            if (dq.empty()) {
                cout << "error\n";
                return;
            }
            if (isRev)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }
    
    // 결과 출력
    cout << '[';
    if (isRev) {
        // 역순으로 출력
        for (int i = dq.size() - 1; i >= 0; i--) {
            cout << dq[i];
            if (i > 0) cout << ',';
        }
    }
    else {
        // 정순으로 출력
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i];
            if (i < dq.size() - 1) cout << ',';
        }
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        func();
    }
    return 0;
}