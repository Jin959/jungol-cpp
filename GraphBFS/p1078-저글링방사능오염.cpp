/*
* 3�� �Ŀ� �״´ٴ� ���� ������ �� üũ�� �ʿ䰡 ����.
* ������ ����� +3 �ϸ� ����� ��� ���۸��� �׾��ִ�.
* 
* ������� �ʾ� ��Ƴ��� ���۸��� üũ���ָ�ȴ�. O(N*N)
* 
* O(N*N + N*N) = 20000
* 
* �׷��� �� ���� �޸� ������ 64MB �̴�.
* int(long) ���� 100 by 100 �迭�� ũ���
* 4 * 10^4 bytes = 40 KB = 0.04MB
* ����ϴ�.
* 
*/

/*
* - �Է��� �ڷ����� ��Ȯ�� �� ��.
* 
* MAP �� string���� �������� , int �� �������� �� �����Ѵ�. ó���� int���� �˰� �� ������ �� ����� �̻��ϰ� ���Դ�.
* �̷����� ���� ����뿡 30���� ���. ó�� �ڵ带 ¥�¸�ŭ �ð��� �ɷȴ�.
* 
* ������ �������� ��ǥ��ȣ�� 1���� �����ϱ� ������ ��� üũ�� ���� ���� �ؾ��� ���� �־���.
* �Է��� �޾��� ��, y, x �� 1�� ����. MAP �� string�̱� ������ ��¿ �� ������. 
* �̷� ���� �Էº��� 1�۾��� y, x�� �����ϵ��� �ؾ� �ߴµ� �̹� ¥���� �ڵ带 ������ϴµ� �� �����ɷȴ�.
* ��ģ�� ���� ������ ����.
* 
* 1. input() ���� for (int i = 0; i < y; i++) cin >> MAP[i]; �� �ƴ϶�
*	for (int i = 0; i <= y; i++) cin >> MAP[i]; ���� �ߴ�.
* 2. isOut() ���� n.y >= y �� �ƴ϶� n.y > y ���� �ߴ�.
* 3. calc() ���� for (int i = 0; i < y; i++) �� �ƴ϶� for (int i = 0; i <= y; i++) ���� �ߴ�.
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

#define MAXN 100

using namespace std;

struct Node {
	int y, x;
} start;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

int y, x;
string MAP[MAXN];
int cost[MAXN][MAXN];	// ���۸��� ���� ���� �湮ó���� �ϰ� ���ش�.
int t, rest;

void input() {
	cin >> x >> y;	
	x--; y--;	// ��ǥ��ȣ 1���� ����. ���⼭ ��� üũ�� ���� ���� �ؾ��� ���� �����.
	for (int i = 0; i <= y; i++) cin >> MAP[i];
	cin >> start.x >> start.y;
	start.x--; start.y--;
}

bool isOut(Node n) {
	return n.y < 0 || n.y > y || n.x < 0 || n.x > x;
}

void bfs() {
	queue<Node> q;
	q.push(start);
	MAP[start.y][start.x] = '0';	// ���۸� ���

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Node nxt = { now.y + dy[i], now.x + dx[i] };

			if (isOut(nxt)) continue;
			if (MAP[nxt.y][nxt.x] == '0') continue;	// ���۸� ����. �湮���� üũ ����� ���� �ϰ� �ȴ�.

			MAP[nxt.y][nxt.x] = '0';	// ���۸� ���
			cost[nxt.y][nxt.x] = cost[now.y][now.x] + 1;
			q.push(nxt);
		}
	}
}

void calc() {
	for (int i = 0; i <= y; i++) {
		for (int j = 0; j <= x; j++) {
			if (MAP[i][j] == '1') rest++;
			if (cost[i][j] != 0) t = max(t, cost[i][j]);
		}
	}
}

int main() {
	input();
	bfs();
	calc();
	cout << t + 3 << endl << rest;	// 3�� �� ���۸� �� ������ �ѹ��� ó��

	return 0;
}