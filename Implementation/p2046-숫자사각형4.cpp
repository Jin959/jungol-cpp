// http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1316&sca=2010

#include <iostream>

#define MAXN 100

using namespace std;

int n, m;
int arr[MAXN][MAXN];

void M1() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			arr[y][x] = y + 1;
		}
	}
}

void M2() {
	for (int y = 0; y < n; y++) {
		
		for (int x = 0; x < n; x++) {
			if (y % 2 == 0) {
				arr[y][x] = x + 1;
			}
			else {
				arr[y][x] = n - x;
			}
		}
	}
}

void M3() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int dan = y + 1;
			arr[y][x] = dan * (x + 1);
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
	cin >> n >> m;

	switch (m) {
	case 1:
		M1();
		break;
	case 2:
		M2();
		break;
	case 3:
		M3();
		break;
	}
	
	print();

	return 0;
}