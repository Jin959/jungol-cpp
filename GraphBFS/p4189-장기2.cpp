#include <iostream>
#include <queue>

#define MAXN 1000
#define MAXM 1000

using namespace std;

struct Node {
	int y, x;

	bool operator==(Node node) {
		return this->y == node.y && this->x == node.x;
	}
};
Node ma, zol;

int dy[] = { 2, 2, 1, 1, -2, -2, -1, -1 };
int dx[] = { 1, -1, 2, -2, 1, -1, 2, -2 };

int n, m;
bool visited[MAXN][MAXM];
int MAP[MAXN][MAXM];

bool isOut(Node node) {
	return node.y < 0 || node.y >= n || node.x < 0 || node.x >= m;
}

void bfs() {
	queue<Node> q;
	q.push(ma);
	visited[ma.y][ma.x] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (now == zol) return;

		for (int i = 0; i < 8; i++) {
			Node nxt = {now.y + dy[i], now.x + dx[i]};
			if (isOut(nxt)) continue;
			if (visited[nxt.y][nxt.x]) continue;
			
			visited[nxt.y][nxt.x] = true;
			MAP[nxt.y][nxt.x] = MAP[now.y][now.x] + 1;
			q.push(nxt);
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> ma.y >> ma.x >> zol.y >> zol.x;

	ma.y--; ma.x--; // 1,1 부터 시작.
	zol.y--; zol.x--;

	bfs();

	cout << MAP[zol.y][zol.x];

	return 0;
}