#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100001

int main()
{
    int me, sis;
    cin >> me >> sis;

    vector<int> dist(MAX, -1);
    queue<int> q;

    if (me == sis)
    {
        cout << 0;
        return 0;
    }
    dist[me] = 0;
    q.push(me);

    while (!q.empty())
    {
        me = q.front();
        q.pop();

        vector<int> moves{ me - 1, me + 1, me * 2 };
        for (auto move : moves)
        {
            if (move >= 0 && move < MAX && dist[move] == -1)
            {
                dist[move] = dist[me] + 1;
                if (move == sis)
                {
                    cout << dist[move];
                    return 0;
                }
                q.push(move);
            }
        }
    }

    return 0;
}