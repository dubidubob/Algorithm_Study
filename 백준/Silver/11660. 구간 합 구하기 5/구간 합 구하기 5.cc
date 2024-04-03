#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N>> M;

    vector<vector<int>> partSum(N + 1, vector<int>(N + 1, 0));
    int input = 0;
    int x1, y1, x2, y2;
    int partSumOut = 0;

    for (int i = 1; i <= N; i++) {//모든 부분합 이차 vector 구함
        for (int j = 1; j <= N; j++) {
            cin >> input;
            partSum[i][j] = input + partSum[i - 1][j] + partSum[i][j - 1] - partSum[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        partSumOut = partSum[x2][y2] + partSum[x1 - 1][y1 - 1] - partSum[x1 - 1][y2] - partSum[x2][y1 - 1];
        cout << partSumOut<<"\n";
    }
}