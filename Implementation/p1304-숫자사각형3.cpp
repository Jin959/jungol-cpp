#include <iostream>

#define MAXN 100

using namespace std;

int arr[MAXN][MAXN];
int n;

void makeArr() {
	int cnt = 1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			arr[y][x] = cnt++;
		}
	}
}

int main() {
	cin >> n;

	makeArr();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}