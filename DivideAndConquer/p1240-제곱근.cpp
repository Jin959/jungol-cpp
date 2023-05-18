#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	long long lb = 1, ub = n;
	long long mid;
	while (1) {
		mid = (lb + ub) / 2;

		// �̰�� �������� ���� �κ��� mid�� ��. ex) 3
		if (lb > ub) {
			break;
		}

		if (mid == n / mid) { // mid * mid == n, typeof(mid) == long long �����÷ζ���
			break;
		}

		if (mid < n / mid) { // mid * mid == n
			lb = mid + 1;
		}
		else {
			ub = mid - 1;
		}
	}

	cout << mid;

	return 0;
}