// https://jungol.co.kr/problem/1082
// ������带 ť�� �ִ� ���� �ؾ 20�� �ظ̴�.
// �������� ���ÿ� �̵��ϴ� Ž��

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
			//����� 'D'�� ǥ���ǰ�, ��찡 ó���� ���ִ� ��ġ�� 'S'�� ǥ�õȴ�.
			if (MAP[i][j] == 'S') start = { i, j };
			if (MAP[i][j] == 'D') goal = { i, j };
			//����ִ� ĭ�� '.'�� ǥ�õǰ�, ���� '*'��, ������ 'X'�� ǥ�õǾ��ִ�.
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
	// ���� ������ �Ͱ� ���ÿ� ��찡 �̵��Ѵ�.
	for (int i = 0; i < fires.size(); i++) {
		q.push({ fires.at(i) });
	}

	bool is_arrived = false;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (is_arrived) break; // �����ϸ� Ž������

		if (MAP[now.y][now.x] == '*') { // ���� ������ ��
			for (int i = 0; i < 4; i++) {
				Node nxt = { now.y + dy[i], now.x + dx[i] };

				if (is_out(nxt)) continue;
				if (MAP[nxt.y][nxt.x] == 'X' || MAP[nxt.y][nxt.x] == 'D') continue; //��'*'�� ����'X'�� ���'D'�� �Ű����� �ʴ´�.
				if (MAP[nxt.y][nxt.x] == '*') continue; // �̹� �������� ���� �ʴ´�.

				MAP[nxt.y][nxt.x] = '*';
				// ������带 ť�� �ִ� ���� �ؾ 20�� �ظ̴�.
				q.push(nxt);
			}
		}
		else { // ��찡 �̵��ϴ� ��
			for (int i = 0; i < 4; i++) {
				Node nxt = { now.y + dy[i], now.x + dx[i] };

				if (is_out(nxt)) continue;
				if (visited[nxt.y][nxt.x]) continue;
				if (MAP[nxt.y][nxt.x] == '*' || MAP[nxt.y][nxt.x] == 'X') continue; // ���� �Ұ� ������ ������ ���Ѵ�.

				visited[nxt.y][nxt.x] = true;
				cost[nxt.y][nxt.x] = cost[now.y][now.x] + 1;
				// ������带 ť�� �ִ� ���� �ؾ 20�� �ظ̴�.
				q.push(nxt);

				// �����ϸ� Ž������
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