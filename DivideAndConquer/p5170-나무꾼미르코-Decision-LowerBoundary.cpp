// Parametric Search : lower boundary �� �ִ밪�� ã�� �����̴�.
/*
T T T | T | F | F F
      ��  ��  �ȵ�
*/

/*
7 184
47 88 100 29 9 7 34

22
*/

#include <iostream>

#define MAXN 1'000'000
#define MAXM 2'000'000'000

using namespace std;

int n, m;
int h[MAXN];
int max_h = -1;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (h[i] > max_h) {
			max_h = h[i];
		}
	}
}

long long getWoodAcc(int mid) {
	long long acc = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] > mid) acc += (h[i] - mid);
	}
	return acc;
}

int main() {
	input();

	int lb = 0, ub = max_h;
	long long acc = 0;
	int mid = 0; // ���ܱ� ����
	while (1) {
		mid = (lb + ub) / 2;
		if (lb + 1 == ub) break; // lb�� ub�� ��迡�� ������ ���̴�.

		acc = getWoodAcc(mid);

		if (acc >= m) {
			lb = mid;
		}
		else {
			ub = mid; // ������ ���ڶ�� �ȵǱ� ������ ub = mid - 1�ϰ� lb > ub ũ�ν� �����Ǿ� �Ѿ���Ѵ�.
		}
	}

	cout << lb;

	return 0;
}