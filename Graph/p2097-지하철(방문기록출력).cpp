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

		// ���⼭ nxt = now.v + 1 ���� Ž�� �ϸ� �ȵȴ�. �ݵ�� ��� �����θ� �湮 �� �� �ִ� ���� �ƴϱ� ����
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

// �湮 Ʈ�� ���� ��ȸ
// union-find �� find ó�� parent[now] == now �� ��찡 ���� ������ �� �� ����. Ž�� �� ��� ������ ������ ����.
void findParent(int now) {
	if (now == 0) {
		cout << now + 1 << ' '; // ���� 1����
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
	dijkstra(1 - 1); // ���� 1
	print();

	return 0;
}