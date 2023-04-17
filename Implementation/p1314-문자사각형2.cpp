#include <iostream>

#define MAXN 100

using namespace std;

char arr[MAXN][MAXN];
int n;

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

	int cnt = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (x % 2 == 0) {
				arr[y][x] = 'A' + cnt++;
			}
			else {
				arr[n-1 - y][x] = 'A' + cnt++;
			}
			
			if ('A' + cnt > 'Z') cnt = 0;
		}
	}

	print();

	return 0;
}