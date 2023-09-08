/*
* 집 -> X -> 집 이 가장 오래걸리는 꿀꿀이는?
* 
* "목적지 X" -> "각 꿀꿀이 집" 의 최단 경로를 구하고
* 각 "각 꿀꿀이 집" 노드 별로 "목적지 X"까지 최단 거리를 구해야 하는 것 처럼 보인다.
* 
* 이경우 O(ElogV) = MlogN + NMlogN = (1 + 1e3)1e4 * log(1e3) ~ 1e7 * 10 ~ 1e8
* -> T(n) ~ 1초로 TLE 가능성 있음.
* 
* 그래프가 단방향이다.
* 방향을 반대로 뒤집어 그래프를 하나 더 만든다.
* 
* 1. 원래의 그래프에서 "목적지 X" -> "각 꿀꿀이 집"까지 돌아갈 때의 최단 거리를 알 수 있다.
* 2. 뒤집은 그래프로 "각 꿀꿀이 집" -> "목적지 X" 로 올때의 최단 거리를 알 수 있다.
* 
* Dijkstra로 2번 만 돌려서 구할 수 있다.
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

int n, m, x;				// 꿀꿀이들, 간선, x는 축제 목적지 장소
int dist[2][MAXN + 1];			// dist[0] : X->집, dist[1] : 집->X
bool used[MAXN + 1];
vector<Edge> adj[2][MAXN + 1];	// adj[0] : X->집, adj[1] : 집->X
priority_queue<Node> pq;

void input() {
	cin >> n >> m >> x;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		adj[0][from].push_back({to, cost});		// X -> 집 으로 돌아올때 사용
		adj[1][to].push_back({from , cost});	// 집 -> X 로 갈떄 사용
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