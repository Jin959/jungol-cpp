// ���鸸 ���´ٰ� ���� ��, ��ŭ �� ������ z�� ���ϴ��� ���
// ��ŭ �������� z �� ���ϳĴ� ���� z �� �� ���� ���� ���� �Ͱ� ����.
// ��, upper boundary�� �ּҰ��� ã�� �����̴�.

/*
in

1000000000 989999999

out

100
*/

#include <iostream>

#define MAXX 1'000'000'000

using namespace std;

long long x, y, z; // ������ ���� ��, ������ ���¼�, ������ ���� Ȯ��

void input() {
	cin >> x >> y;
	z = (y * 100) / x;
}

long long getRate(int mid) {
	return ((y + mid) * 100) / (x + mid);
}

int main() {
	input();

	int lb = 0, ub = MAXX;
	int mid;
	int new_rate;
	while (1) {
		if (lb + 1 == ub) break;	// �� ������ ����.
		
		mid = (lb + ub) / 2;

		new_rate = getRate(mid);

		if (new_rate <= z) {		// ���� Ȯ���� �Ⱥ��ϴ� ����
			lb = mid;
		}
		else {
			ub = mid;
		}
	}

	if (getRate(ub) == z) cout << -1;
	else cout << ub;

	return 0;
}