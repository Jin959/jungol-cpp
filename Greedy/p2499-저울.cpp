// ¼öÇĞÀû ±Í³³¹ı

#include <iostream>
#include <algorithm>

#define MAXN 1000

using namespace std;

int n;
int pend[MAXN];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pend[i];
	}
}

int main() {
	input();
	sort(pend, pend + n);
	if (pend[0] != 1) {
		cout << 1;
		return 0;
	}

	long long s = 1;
	int min_impossible = -1;
	for (int i = 1; i < n - 1; i++) {
		if (s + pend[i] + 1 < pend[i + 1]) {
			min_impossible = s + pend[i] + 1;
			break;
		}
		s += pend[i];
	}

	if (min_impossible == -1) {
		min_impossible = s + pend[n - 1] + 1;
	}

	cout << min_impossible;

	return 0;
}