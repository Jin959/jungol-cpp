#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 100
#define MAXM 100
#define MAXK 100

using namespace std;

struct Node {
	int y, x;
};

int m, n, k;
Node s[MAXK];
Node e[MAXK];
int MAP[MAXM][MAXN];
bool visited[MAXM][MAXN];
int cnt, width;
vector<int> v;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void input() {
	cin >> m >> n >> k;

	Node start, end;
	for (int i = 0; i < k; i++) {
		cin >> start.x >> start.y >> end.x >> end.y;
		for (int y = start.y; y < end.y; y++) {
			for (int x = start.x; x < end.x; x++) {
				MAP[y][x] = -1;
			}
		}
	}
}

void print() {
	cout << cnt << '\n';
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		cout << v[i] << ' ';
	}
}

bool isOut(Node node) {
	return node.y < 0 || node.y >= m || node.x < 0 || node.x >= n;
}

void dfs(Node now) {
	visited[now.y][now.x] = true;
	width++;
	
	for (int i = 0; i < 4; i++) {
		Node nxt = { now.y + dy[i], now.x + dx[i] };

		if (isOut(nxt)) continue;
		if (visited[nxt.y][nxt.x]) continue;
		if (MAP[nxt.y][nxt.x] == -1) continue;

		dfs(nxt);
	}
}

int main() {
	input();

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (visited[y][x]) continue;
			if (MAP[y][x] != 0) continue;

			width = 0;
			dfs({ y, x });
			v.push_back(width);
			cnt++;
		}
	}

	sort(v.begin(), v.end());

	print();

	return 0;
}