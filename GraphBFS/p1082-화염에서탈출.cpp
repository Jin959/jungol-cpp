// https://jungol.co.kr/problem/1082
// 다음노드를 큐에 넣는 것을 잊어서 20분 해맸다.
// 여러개가 동시에 이동하는 탐색

#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

#define MAXR 50
#define MAXC 50

int r, c;
string MAP[MAXR];
int cost[MAXR][MAXC];
bool visited[MAXR][MAXC];

struct Node {
	int y, x;
};
Node start, goal;
vector<Node> fires;

int dy[] = {0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0 };

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> MAP[i];
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//요새는 'D'로 표현되고, 재우가 처음에 서있는 위치는 'S'로 표시된다.
			if (MAP[i][j] == 'S') start = { i, j };
			if (MAP[i][j] == 'D') goal = { i, j };
			//비어있는 칸은 '.'로 표시되고, 불은 '*'로, 바위는 'X'로 표시되어있다.
			if (MAP[i][j] == '*') fires.push_back({ i, j });
		}
	}
}

bool is_out(Node node) {
	return node.y < 0 || node.y >= r || node.x < 0 || node.x >= c;
}

void bfs() {
	queue<Node> q;
	visited[start.y][start.x] = true;
	q.push(start);
	// 불이 번지는 것과 동시에 재우가 이동한다.
	for (int i = 0; i < fires.size(); i++) {
		q.push({ fires.at(i) });
	}

	bool is_arrived = false;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (is_arrived) break; // 도착하면 탐색종료

		if (MAP[now.y][now.x] == '*') { // 불이 번지는 턴
			for (int i = 0; i < 4; i++) {
				Node nxt = { now.y + dy[i], now.x + dx[i] };

				if (is_out(nxt)) continue;
				if (MAP[nxt.y][nxt.x] == 'X' || MAP[nxt.y][nxt.x] == 'D') continue; //불'*'은 바위'X'와 요새'D'에 옮겨지지 않는다.
				if (MAP[nxt.y][nxt.x] == '*') continue; // 이미 번진곳은 가지 않는다.

				MAP[nxt.y][nxt.x] = '*';
				// 다음노드를 큐에 넣는 것을 잊어서 20분 해맸다.
				q.push(nxt);
			}
		}
		else { // 재우가 이동하는 턴
			for (int i = 0; i < 4; i++) {
				Node nxt = { now.y + dy[i], now.x + dx[i] };

				if (is_out(nxt)) continue;
				if (visited[nxt.y][nxt.x]) continue;
				if (MAP[nxt.y][nxt.x] == '*' || MAP[nxt.y][nxt.x] == 'X') continue; // 재우는 불과 바위를 지나지 못한다.

				visited[nxt.y][nxt.x] = true;
				cost[nxt.y][nxt.x] = cost[now.y][now.x] + 1;
				// 다음노드를 큐에 넣는 것을 잊어서 20분 해맸다.
				q.push(nxt);

				// 도착하면 탐색종료
				if (MAP[nxt.y][nxt.x] == 'D') {
					is_arrived = true;
					break;
				}
			}
		}
	}

	if (cost[goal.y][goal.x] == 0) cout << "impossible";
	else cout << cost[goal.y][goal.x];
}

int main() {
	input();
	bfs();

	return 0;
}