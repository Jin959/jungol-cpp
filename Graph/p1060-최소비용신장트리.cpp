// MST - Kruskal

#include <iostream>
#include <queue>

#define MAXN 100

using namespace std;

struct Edge {
	int u, v, cost;

	bool operator< (Edge edge) const {
		return this->cost > edge.cost;
	}
};

int adj[MAXN][MAXN];
int n;
int parent[MAXN];
priority_queue<Edge> pq;

void init() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (!adj[i][j]) continue;
			pq.push({ i, j, adj[i][j] });
		}
	}

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int find(int i) {
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

int main() {
	init();

	int edge_cnt = 0;
	int acc = 0;
	while (!pq.empty()) {
		if (edge_cnt == n - 1) break; // 트리는 간선이 n - 1;
		Edge now = pq.top();
		pq.pop();

		if (find(now.u) != find(now.v)) { // 순환여부 및 이미 연결된 경우
			unite(now.u, now.v);
			acc += now.cost;
			edge_cnt++;
		}
	}

	cout << acc;

	return 0;
}