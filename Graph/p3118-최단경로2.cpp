// Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAXN 100000
#define INF 21e8

using namespace std;


struct Node {
	int vertex, acc;

	bool operator< (Node node) const {
		return acc > node.acc;
	}
} start{ 0, 0 };

struct Edge {
	int vertex, cost;
};


int n, m;
int visited[MAXN];
int dist[MAXN];
vector<Edge> adj[MAXN];

void init() {
	cin >> n >> m;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		adj[from - 1].push_back({ to - 1, cost });
	}

	fill(dist, dist + n, INF);
	memset(visited, 0, sizeof(visited));
}

int dijkstra() {
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	priority_queue<Node> pq;
	pq.push(start);

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (visited[now.vertex]) continue;
		visited[now.vertex] = 1;

		for (Edge next : adj[now.vertex]) {
			if (now.acc + next.cost < dist[next.vertex]) {
				dist[next.vertex] = now.acc + next.cost;
				pq.push({ next.vertex, dist[next.vertex] });
			}
		}
	}

	return dist[n - 1];
}

int main() {
	init();

	cout << dijkstra();

	return 0;
}