#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int idx;
	int dist;
};

struct Subtree {
	int cnt;
	long long distSum;
};

vector<vector<Node>> tree;
vector<Subtree> subtree;
vector <long long> total;

int n;
// top down : 맨 위 노드는 완료했으니 바로 밑 노드부터, 자신의 서브트리가 아닌 외부 노드 = 바로 위 노드의 토탈 - 내 서브트리 - 나와 그 사이 브릿지*내 서브트리 노드 개수 + 나와 그 사이 브릿지*그의 서브트리 노드 개수
//  이걸 더하면 된다.
// 부모 그리고 너를 시전
// 부모의 totalCost에서 내 걸 뺀다. 그리고 n-내 서브노드 개수 * 브릿지 + 내 서브노드 개수*브릿지로 totalCost 갱신
// 각 child node 갱신

void topDown(int parentIdx, Node cur)
{
	total[cur.idx] = total[parentIdx] - cur.dist * (2 * subtree[cur.idx].cnt - n);
	for (auto c : tree[cur.idx])
	{
		if (c.idx == parentIdx) continue;

		topDown(cur.idx, c);
	}
}

// bottom up : 밑 각자의 노드까지의 토탈을 계산하고, 위 부모까지의 서브트리 토탈을 계산해서 올려보낸다.
// 부모, 그리고 너로 내려보내기
Subtree bottomUp(int parentIdx, Node cur)
{
	if (tree[cur.idx].size() == 1 && tree[cur.idx][0].idx == parentIdx) // 만약 리프노드라면
	{
		subtree[cur.idx].cnt = 1;//	subtree num는 1개, 내 토탈은 0
		return { 1, cur.dist };// return subtree num 1개, 니 토탈은 우리 사이
	}

	subtree[cur.idx].cnt = 1;// 내 subtreenum 1
	for (auto c : tree[cur.idx])// 내 child 수만큼 밑으로 돌려
	{
		if (c.idx == parentIdx) continue;

		auto r = bottomUp(cur.idx, c);
		subtree[cur.idx].cnt += r.cnt;// += 자식들 subtree num
		subtree[cur.idx].distSum += r.distSum; // += 자식들 total 합
	}

	return { subtree[cur.idx].cnt, subtree[cur.idx].distSum + cur.dist * subtree[cur.idx].cnt }; // return subtree num, 니 토탈(자식들 total + 우리 사이*subtree num)
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	tree.resize(n + 1);
	subtree.resize(n + 1, { 0, 0 });
	total.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		tree[u].push_back({ v,d });
		tree[v].push_back({ u,d });
	}

	// 마지막이 그러면 최종 토탈이 되겠지?
	Node start = { 1, 0 };
	bottomUp(0, start);

	// 서브 트리 정리 완료.
	// total 정리 시작
	total[0] = subtree[1].distSum;
	topDown(0, start);

	for (int i = 1; i <= n; i++)
	{
		cout << total[i] << "\n";
	}

	return 0;
}
