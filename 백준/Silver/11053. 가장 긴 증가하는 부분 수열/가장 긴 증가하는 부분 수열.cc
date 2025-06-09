#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> lis = {0};

    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;

        int curIdx = lis.size()-1;
        if (lis[curIdx] < cur) {
            lis.push_back(cur);
            curIdx = lis.size() - 1;
        }
        else if (lis[curIdx] > cur) {
            int front, end, mid;
            front = 0; end = curIdx;
            
            while (front <= end) {
                mid = (front + end) / 2;
                if (lis[mid] < cur) { // 더 작은 값이면 mid+1 이후에 끼워야 한다
                    front = mid + 1;
                }
                else {  // lis[mid] >= cur 이면, 이 위치나 그 왼쪽에 끼워질 수 있다
                    end = mid - 1;
                }
            }
            // 반복문 종료 시 front == 첫 번째 lis[i] >= cur 의 인덱스
            lis[front] = cur;
        }
        //for (int j : lis)
        //    cout << j << " ";
        //cout << "\n";
    }

    cout << lis.size() - 1;

    return 0;
}
