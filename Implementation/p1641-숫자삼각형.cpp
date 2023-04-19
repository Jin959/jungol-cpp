#include <iostream>
#include <cstring>

#define MAXN 100

using namespace std;

int n, m;
int arr[MAXN][MAXN * 2]; // because of case 2

void wirte(int t) {
	int cnt = 1;
	switch(t) {
	case 1:
		for (int y = 0; y < n; y++) {
			for (int x = 0; x <= y; x++) {
				if (y % 2 == 0) arr[y][x] = cnt++;
				else arr[y][y - x] = cnt++;
			}
		}
		break;
	case 2:
		cnt = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < y; x++) {
				arr[y][x] = -2;
			}
			for (int x = y; x < 2 * n - y - 1; x++) { // y = -x + 2(n - 1)
				arr[y][x] = cnt;
			}
			cnt++;
		}
		break;
	case 3:
		for (int y = 0; y < n / 2; y++) {
			cnt = 1;
			for (int x = 0; x <= y; x++) {
				arr[y][x] = cnt++;
			}
		}
		for (int y = n / 2; y < n; y++) {
			cnt = 1;
			for (int x = 0; x < n - y; x++) { // y = -x + (n-1)
				arr[y][x] = cnt++;
			}
		}
		break;
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (arr[i][j] == -1) continue;
			else if (arr[i][j] == -2) {
				cout << "  ";
				continue;
			}
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	if (n < 1 || n > MAXN || n % 2 == 0 || 1 > m || m > 3) {
		cout << "INPUT ERROR!";
		return 0;
	}
	memset(arr, -1, sizeof(arr));

	wirte(m);

	print();

	return 0;
}