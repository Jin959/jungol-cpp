#include <iostream>

#define MAXN 100

using namespace std;

int n, m;
char arr[MAXN][MAXN];


void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void write(int t) {
	switch (t) {
	case 1:
		for (int y = 0; y < n / 2; y++) {
			for (int x = 0; x <= y; x++) {
				arr[y][x] = '*';
			}
		}
		for (int y = n / 2; y < n; y++) {
			for (int x = 0; x < n - y; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	case 2:
		for (int y = 0; y < n / 2; y++) {
			for (int x = 0; x < n / 2 - y; x++) {
				arr[y][x] = ' ';
			}
			for (int x = n / 2 - y; x <= n / 2; x++) {
				arr[y][x] = '*';
			}
		}
		for (int y = n / 2; y < n; y++) {
			for (int x = 0; x < y - n / 2; x++) {
				arr[y][x] = ' ';
			}
			for (int x = y - n / 2; x <= n / 2; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	case 3:
		for (int y = 0; y < n / 2; y++) {
			for (int x = 0; x < y; x++) {
				arr[y][x] = ' ';
			}
			for (int x = y; x < n - y; x++) {
				arr[y][x] = '*';
			}
		}
		for (int y = n / 2; y < n; y++) {
			for (int x = 0; x < n - y - 1; x++) {
				arr[y][x] = ' ';
			}
			for (int x = n - y - 1; x <= y; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	case 4:
		for (int y = 0; y < n / 2; y++) {
			for (int x = 0; x < y; x++) {
				arr[y][x] = ' ';
			}
			for (int x = y; x <= n / 2; x++) {
				arr[y][x] = '*';
			}
		}
		for (int y = n / 2; y < n; y++) {
			for (int x = 0; x < n / 2; x++) {
				arr[y][x] = ' ';
			}
			for (int x = n / 2; x <= y; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	}
}

int main() {
	cin >> n >> m;
	if (n > MAXN || n < 1 || n%2 == 0 || m < 1 || m > 4) {
		cout << "INPUT ERROR!";
		return 0;
	}

	write(m);

	print();

	return 0;
}