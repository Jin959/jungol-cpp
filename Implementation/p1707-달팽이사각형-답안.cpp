// 배열의 out of range 때문에 1로 다채운 뒤 loop으로만 돌린다.

#include <iostream>

#define MAXN 100

using namespace std;

int arr[MAXN + 1][MAXN + 1];
int n;

// 바람개비 모양으로 채워진다.
void makeFence() {
	for (int i = 0; i <= n + 1; i++) { // 아래위, 좌우 두짝 모두 2칸이 줄이 채워지므로 n + 1까지 채워야 한다.
		arr[0][i] = arr[n + 1][i] = 1;
		arr[i][0] = arr[i][n + 1] = 1;
	}
}

void snail() {
	int i;
	int y = 1, x = 0, cnt = 1;

	while (cnt <= n * n) {
		while (arr[y][x + 1] == 0) { // 우
			arr[y][++x] = cnt++;
		}
		while (arr[y + 1][x] == 0) { // 하
			arr[++y][x] = cnt++;
		}
		while (arr[y][x - 1] == 0) { // 좌
			arr[y][--x] = cnt++;
		}
		while (arr[y - 1][x] == 0) { // 상
			arr[--y][x] = cnt++;
		}
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

	makeFence();
	snail();
	print();

	return 0;
}