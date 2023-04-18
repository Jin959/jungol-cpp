#include <iostream>

#define MAXN 100

using namespace std;

char arr[MAXN][MAXN * 2];
int n;

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (!arr[i][j]) continue;
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int main() {
	cin >> n;

	if (n < 1 || n > MAXN || n % 2 == 0) {
		cout << "INPUT ERROR!";
		return 0;
	}
	
	for (int y = 0; y < n / 2; y++) {
		// y, x -> y = x
		for (int x = 0; x < y; x++) {
			arr[y][x] = ' ';
		}
		// y, x : 0, 0 -> 1, 3 -> 2, 6 -> ... y = x / 3
		for (int x = y; x <= 3 * y; x++) {
			arr[y][x] = '*';
		}
	}
	for (int y = n / 2; y < n; y++) {
		// y = - x + n-1
		for (int x = 0; x < n - 1 - y; x++) {
			arr[y][x] = ' ';
		}
		// y, x : 6, 0 -> 5, 3 -> 4, 6 ... y = - x / 3 + n-1
		for (int x = n - 1 - y; x <= 3 * (n - 1 - y); x++) {
			arr[y][x] = '*';
		}
	}

	print();

	return 0;
}