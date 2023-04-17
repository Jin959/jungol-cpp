#include <iostream>
#include <cmath>

using namespace std;

float n;
char v;
char arr[100][100];

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(arr[i][j] == 0) continue;
			else cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	if (n > 100 || n == 0 || (int)n%2 == 0) {
		cout << "INPUT ERROR";
		return 0;
	}

	int mid = n / 2;
	int ox = mid, oy = mid;
	int x, y;
	v = 'A';

	while (ox >= 0) {
		x = ox;
		y = oy;
		while (y < n - oy) {
			arr[y][x] = v++;
			if (v > 'Z') v = 'A';
			y++;
		}
		ox--;
		oy--;
	}

	print();

	return 0;
}