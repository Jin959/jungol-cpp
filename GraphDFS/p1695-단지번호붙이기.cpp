#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAXN 25

using namespace std;

int n;
int MAP[MAXN][MAXN];
int visited[MAXN][MAXN];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

vector<int> spaces;
int space;
int cnt;

struct Node {
	int y, x;
};

void input() {
	cin >> n;
	string tmp = "";
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			MAP[i][j] = int(tmp[j] - '0');
		}
	}
}

void print() {
	cout << cnt << endl;

	int sz = spaces.size();
	for (int i = 0; i < sz; i++) {
		cout << spaces[i] << endl;
	}
}

bool isOut(Node node) {
	return node.y >= n || node.y < 0 || node.x >= n || node.x < 0;
}

void dfs(Node now) {

	for (int i = 0; i < 4; i++) {
		Node nxt = { now.y + dy[i], now.x + dx[i] };

		if (isOut(nxt)) continue;
		if (MAP[nxt.y][nxt.x] == 0) continue;
		if (visited[nxt.y][nxt.x]) continue;

		visited[nxt.y][nxt.x] = 1;
		space++;
		dfs(nxt);
	}
}

int main() {
	input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			if (MAP[i][j] == 0) continue;
			visited[i][j] = 1;
			space = 1;

			dfs({ i , j });

			spaces.push_back(space);
			cnt++;
		}
	}

	sort(spaces.begin(), spaces.end());

	print();

	return 0;
}