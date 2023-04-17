#include <iostream>

#define MAXN 100

using namespace std;

int n;
char arr[MAXN][MAXN];

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) cout << "  ";
			else cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> n;

	char value = 'A';
	for (int oy = 0; oy < n; oy++) {
		for (int x = n - 1, y = oy; y < n; x--, y++) {
			arr[y][x] = value++;
			if (value > 'Z') value = 'A';
		}
	}

	print();

	return 0;
}