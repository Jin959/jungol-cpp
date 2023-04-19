// �迭�� out of range ������ 1�� ��ä�� �� loop���θ� ������.

#include <iostream>

#define MAXN 100

using namespace std;

int arr[MAXN + 1][MAXN + 1];
int n;

// �ٶ����� ������� ä������.
void makeFence() {
	for (int i = 0; i <= n + 1; i++) { // �Ʒ���, �¿� ��¦ ��� 2ĭ�� ���� ä�����Ƿ� n + 1���� ä���� �Ѵ�.
		arr[0][i] = arr[n + 1][i] = 1;
		arr[i][0] = arr[i][n + 1] = 1;
	}
}

void snail() {
	int i;
	int y = 1, x = 0, cnt = 1;

	while (cnt <= n * n) {
		while (arr[y][x + 1] == 0) { // ��
			arr[y][++x] = cnt++;
		}
		while (arr[y + 1][x] == 0) { // ��
			arr[++y][x] = cnt++;
		}
		while (arr[y][x - 1] == 0) { // ��
			arr[y][--x] = cnt++;
		}
		while (arr[y - 1][x] == 0) { // ��
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