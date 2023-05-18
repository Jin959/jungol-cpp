#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;

	long long lb = 1, ub = n;
	long long mid;
	while (1) {
		mid = (lb + ub) / 2;

		// 이경우 제곱근의 정수 부분이 mid가 됨. ex) 3
		if (lb > ub) {
			break;
		}

		if (mid == n / mid) { // mid * mid == n, typeof(mid) == long long 오버플로때문
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