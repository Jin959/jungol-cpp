#include <iostream>

#define MAXN 100

using namespace std;

int n;
int arr[MAXN][MAXN];
int visited[MAXN][MAXN];

bool isOut(int y, int x) {
	return y >= n || y < 0 || x >= n || x < 0;
}

void trigonalSnail() {
	int y = -1, x = -1, cnt = 0;
	int nxt_y, nxt_x;
	while (cnt < n * (n + 1) / 2) { // 등차수열 합
		while (1) {
			nxt_y = y + 1;
			nxt_x = x + 1;
			if (isOut(nxt_y, nxt_x)) break;
			if (visited[nxt_y][nxt_x]) break;

			arr[y = nxt_y][x = nxt_x] = cnt++ % 10;
			visited[y][x] = 1;
		}
		while (1) {
			nxt_x = x - 1;
			if (isOut(y, nxt_x)) break;
			if (visited[y][nxt_x]) break;

			arr[y][x = nxt_x] = cnt++ % 10;
			visited[y][x] = 1;
		}
		while (1) {
			nxt_y = y - 1;
			if (isOut(nxt_y, x)) break;
			if (visited[nxt_y][x]) break;

			arr[y = nxt_y][x] = cnt++ % 10;
			visited[y][x] = 1;
		}
	}
}

void print() {
	int bnd_x = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bnd_x; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
		bnd_x++;
	}
}

int main() {
	cin >> n;
	
	trigonalSnail();
	print();

	return 0;
}