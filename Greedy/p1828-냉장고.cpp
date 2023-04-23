// Activity Selection Prob
#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct Chemical {
	int lb, ub;
};

bool cmp(Chemical l, Chemical r) {
	return l.ub < r.ub;
}

int n;
Chemical chemi[MAXN];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> chemi[i].lb >> chemi[i].ub;
	}
}

int main() {
	input();

	// 1. "��"�� ���� �Ѵ�.
	sort(chemi, chemi + n, cmp);

	// 2. �ϳ��� ���Ѵ�.
	int idx = 0;
	int cnt = 1;

	// 3. �� �� ���Ѵ�.
	for (int i = 1; i < n; i++) {
		if (chemi[idx].ub < chemi[i].lb) {
			idx = i;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}