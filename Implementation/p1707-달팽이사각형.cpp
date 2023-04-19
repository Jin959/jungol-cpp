#include <iostream>

#define MAXN 100

using namespace std;

int arr[MAXN][MAXN];
int n;
// ©Л го аб ╩С 
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

struct Node {
	int y, x;
};

bool isWall(Node next) {
	int flag = 0;

	if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
		return true;
	}
	else if (arr[next.y][next.x] != 0) {
		return true;
	}

	return false;
}

bool isEnd(Node now) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		Node next = { now.y + dy[i], now.x + dx[i] };
		if (isWall(next)) {
			cnt++;
		}
		else if (arr[next.y][next.x] != 0) {
			cnt++;
		}
	}

	if (cnt == 4) return true;
	else return false;
}

void snail() {
	int dir = 0;
	Node now = { 0, 0 };
	int cnt = 1;
	while (1) {
		arr[now.y][now.x] = cnt++;
		if (isEnd(now)) break;
		Node next = { now.y + dy[dir], now.x + dx[dir] };
		if (isWall(next)) {
			dir = (dir + 1) % 4;
			next = { now.y + dy[dir], now.x + dx[dir] };
		}
		now = next;
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	snail();
	print();

	return 0;
}