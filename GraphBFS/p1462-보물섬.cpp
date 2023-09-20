// https://www.jungol.co.kr/problem/1462

// ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� ���� �� �ð��� �ɸ��� ���� �� �� ���̸� �ִ� �Ÿ��� �̵��ϴ� �ð��� ����Ѵ�.
/*
* �������� ������� ���� �ִܰŸ��� �޶�����.
* O(N * N) * (N * N) ȸ = 50 * 50 * 50 * 50 = 6,250,000
* T(n) < 1��
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

string MAP[MAXN];	// ����(L)�� �ٴ�(W)�� ǥ��
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
	return max_cost;	// �� ������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� ���� �� �ð��� �ɸ��� ���� �� ���� �̵� �ð�
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