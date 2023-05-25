#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 100
#define INF 21e7

using namespace std;

int n, m;
int adj[MAXN][MAXN];
int dist[MAXN];
int visited[MAXN];
int parent[MAXN];

struct Node {
	int v, acc;
};
bool operator< (Node bot, Node top) {
	return bot.acc > top.acc;
}

priority_queue<Node> pq;

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	fill(dist, dist + n, INF);
}

void dijkstra(int start) {
	pq.push({ start, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (now.v == m - 1) break;
		if (visited[now.v]) continue;
		visited[now.v] = 1;

		// 여기서 nxt = now.v + 1 부터 탐색 하면 안된다. 반드시 노드 순으로만 방문 할 수 있는 것이 아니기 때문
		for (int nxt = 0; nxt < n; nxt++) {
			if (adj[now.v][nxt] == now.v) continue;
			if (adj[now.v][nxt] == 0) continue;

			if (now.acc + adj[now.v][nxt] < dist[nxt]) {
				dist[nxt] = now.acc + adj[now.v][nxt];
				pq.push({ nxt, dist[nxt] });

				parent[nxt] = now.v;
			}
		}
	}
}

// 방문 트리 후위 순회
// union-find 의 find 처럼 parent[now] == now 인 경우가 기저 조건이 될 수 없다. 탐색 중 모두 헤집어 버리기 때문.
void findParent(int now) {
	if (now == 0) {
		cout << now + 1 << ' '; // 노드는 1부터
		return;
	}

	findParent(parent[now]);
	cout << now + 1 << ' ';
	return;
}

void print() {
	cout << dist[m - 1] << '\n';
	findParent(m - 1);
}

int main() {
	init();
	dijkstra(1 - 1); // 숙소 1
	print();

	return 0;
}