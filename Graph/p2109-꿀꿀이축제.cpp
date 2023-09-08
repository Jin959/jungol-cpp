/*
* �� -> X -> �� �� ���� �����ɸ��� �ܲ��̴�?
* 
* "������ X" -> "�� �ܲ��� ��" �� �ִ� ��θ� ���ϰ�
* �� "�� �ܲ��� ��" ��� ���� "������ X"���� �ִ� �Ÿ��� ���ؾ� �ϴ� �� ó�� ���δ�.
* 
* �̰�� O(ElogV) = MlogN + NMlogN = (1 + 1e3)1e4 * log(1e3) ~ 1e7 * 10 ~ 1e8
* -> T(n) ~ 1�ʷ� TLE ���ɼ� ����.
* 
* �׷����� �ܹ����̴�.
* ������ �ݴ�� ������ �׷����� �ϳ� �� �����.
* 
* 1. ������ �׷������� "������ X" -> "�� �ܲ��� ��"���� ���ư� ���� �ִ� �Ÿ��� �� �� �ִ�.
* 2. ������ �׷����� "�� �ܲ��� ��" -> "������ X" �� �ö��� �ִ� �Ÿ��� �� �� �ִ�.
* 
* Dijkstra�� 2�� �� ������ ���� �� �ִ�.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAXN 1000
#define MAXM 10000
#define INF 21e8

using namespace std;

struct Node {
	int vertex, acc;

	bool operator<(Node node) const {
		return this->acc > node.acc;
	}
};

struct Edge {
	int to, cost;
};

int n, m, x;				// �ܲ��̵�, ����, x�� ���� ������ ���
int dist[2][MAXN + 1];			// dist[0] : X->��, dist[1] : ��->X
bool used[MAXN + 1];
vector<Edge> adj[2][MAXN + 1];	// adj[0] : X->��, adj[1] : ��->X
priority_queue<Node> pq;

void input() {
	cin >> n >> m >> x;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		adj[0][from].push_back({to, cost});		// X -> �� ���� ���ƿö� ���
		adj[1][to].push_back({from , cost});	// �� -> X �� ���� ���
	}
}

void init(int dist_n[]) {
	while (!pq.empty()) pq.pop();
	fill(dist_n, dist_n + (MAXN + 1), INF);
	memset(used, false, sizeof(used));
}

void dijkstra(int* dist_n, vector<Edge>* adj_n) {
	Node start = { x, 0 };
	pq.push(start);
	dist_n[start.vertex] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (used[now.vertex]) continue;
		used[now.vertex] = true;

		for (Edge nxt : adj_n[now.vertex]) {
			if (now.acc + nxt.cost >= dist_n[nxt.to]) continue;
			dist_n[nxt.to] = now.acc + nxt.cost;
			pq.push({nxt.to, dist_n[nxt.to]});
		}
	}
}

int getMax() {
	int max_dist = 0;

	for (int i = 1; i <= n; i++) {
		max_dist = max(dist[0][i] + dist[1][i], max_dist);
	}

	return max_dist;
}

int main() {
	input();

	for (int i = 0; i < 2; i++) {
		init(dist[i]);
		dijkstra(dist[i], adj[i]);
	}

	cout << getMax();

	return 0;
}