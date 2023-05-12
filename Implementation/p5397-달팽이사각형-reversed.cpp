// 더 나아가서 visited[][]와 isOut()을 사용하면 makeFence()가 없어도 된다.

#include <iostream>

#define MAXN 100

using namespace std;

int n;
int arr[MAXN + 2][MAXN + 2];

void fence() {
	for (int x = 0; x < n + 2; x++) {
		arr[0][x] = 1;
		arr[n + 1][x] = 1;
	}
	for (int y = 0; y < n + 2; y++) {
		arr[y][0] = 1;
		arr[y][n + 1] = 1;
	}
}

void snail() {
	int cnt = 1;
	int y = 1, x = n + 1; // 첫번째 nested loop 때문에 x = n + 1
	while (cnt <= n * n) {
		while (arr[y][x - 1] == 0) arr[y][--x] = cnt++;
		while (arr[y + 1][x] == 0) arr[++y][x] = cnt++;
		while (arr[y][x + 1] == 0) arr[y][++x] = cnt++;
		while (arr[y - 1][x] == 0) arr[--y][x] = cnt++;
	}
}

void print() {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	fence();
	snail();
	print();

	return 0;
}