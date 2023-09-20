// https://www.jungol.co.kr/problem/1462

// 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.
/*
* 시작점이 어딘지에 따라 최단거리가 달라진다.
* O(N * N) * (N * N) 회 = 50 * 50 * 50 * 50 = 6,250,000
* T(n) < 1초
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

#define MAXN 50

using namespace std;

struct Node { int y, x; };

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

string MAP[MAXN];	// 육지(L)나 바다(W)로 표시
bool visited[MAXN][MAXN];
int cost[MAXN][MAXN];
int y, x;

void input() {
	cin >> y >> x;
	for (int i = 0; i < y; i++) cin >> MAP[i];
}

bool isOut(Node node) {
	return node.y < 0 || node.y >= y || node.x < 0 || node.x >= x;
}

int bfs(Node start) {
	int max_cost = 0;
	queue<Node> q;
	q.push(start);
	visited[start.y][start.x] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Node nxt = { now.y + dy[i], now.x + dx[i] };

			if (isOut(nxt)) continue;
			if (MAP[nxt.y][nxt.x] == 'W') continue;
			if (visited[nxt.y][nxt.x]) continue;

			visited[nxt.y][nxt.x] = true;
			cost[nxt.y][nxt.x] = cost[now.y][now.x] + 1;
			max_cost = max(max_cost, cost[nxt.y][nxt.x]);
			q.push(nxt);
		}
	}
	return max_cost;	// 한 섬에서 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳의 이동 시간
}

void init() {
	memset(visited, false, sizeof(visited));
	memset(cost, 0, sizeof(cost));
}

int main() {
	input();
	int ans = 0;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (MAP[i][j] == 'W') continue;	// water
			init();
			int dist = bfs({ i, j });
			ans = max(ans, dist);
		}
	}

	cout << ans;

	return 0;
}