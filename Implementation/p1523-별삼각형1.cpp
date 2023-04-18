#include <iostream>

#define MAXN 100

using namespace std;

char arr[MAXN][MAXN * 2];
int n, m;
int flag;

void print() {
	if (flag == 1) {
		cout << "INPUT ERROR!";
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (arr[i][j] == 0) continue;
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int de;
void write(int t) {
	switch (t) {
	case 1:
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < y + 1; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	case 2:
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n - y; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	case 3:
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n-1 - y; x++) {
				arr[y][x] = ' ';
			}
			for (int x = n-1 - y; x < n + y; x++) {
				arr[y][x] = '*';
			}
		}
		break;
	}
}

int main() {
	cin >> n >> m;

	if (n > MAXN || n < 1 || m < 1 || m > 3) flag = 1;
	else write(m);

	print();

	return 0;
}