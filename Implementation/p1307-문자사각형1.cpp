#include <iostream>

#define MAXN 100

using namespace std;

char arr[MAXN][MAXN];
int n;

void makeArr() {
	int cnt = 0;
	for (int x = n-1; x >= 0; x--) {
		for (int y = n - 1; y >= 0; y--) {
			arr[y][x] = 'A' + cnt++;
			if ('A' + cnt == 'Z' + 1) cnt = 0;
		}
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

	makeArr();
	print();

	return 0;
}