#include <iostream>
#include <vector>
using namespace std;

struct node {
    int idx;
    int weight;
};

vector<vector<node>> tree; 
vector<int> best;
int dp(node cur)
{
    if (tree[cur.idx].size() == 0)
    {
        return cur.weight;
    }

    int maxSum = 0;
    int midMaxFirst = 0;
    int midMaxSecond = 0;
    for (int i = 0; i < tree[cur.idx].size(); i++)
    {
        int childWeights= dp(tree[cur.idx][i]);
        // cout << "\n" << childWeights << " idx : " << tree[cur.idx][i].idx;

        if (midMaxFirst <= childWeights)
        {
            midMaxSecond = midMaxFirst;
            midMaxFirst = childWeights;
        }
        else if(midMaxSecond < childWeights)
        {
            midMaxSecond = childWeights;
        }
    }

    best[cur.idx] = midMaxFirst + midMaxSecond;
    return midMaxFirst + cur.weight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 트리 : 인접리스트, 타고타고 가는 것.
    int n; cin >> n;
    tree.resize(n+1);
    best.resize(n + 1, 0);
    for (int i = 0; i < n-1; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        tree[s].push_back({ e, w });
    }

    dp({ 1, 0 });

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << "\n idx : " << i << " " << best[i];
        result = max(best[i], result);
    }
    cout << result;
    return 0;
}