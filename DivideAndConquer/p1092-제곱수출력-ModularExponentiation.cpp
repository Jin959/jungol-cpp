//Modular Exponentiation(��ⷯ ����) - �ŵ����� ������ ���ϱ�
//CLRS �˰��� - 31.6 ������:������ �ŵ����� page.983
// 
//��ⷯ ������ ��ȯ ������ ������, ������ ���� �й� ��Ģ�� �����ϱ� ������ �������� ����ؼ� �̿��ϴ� Ǯ�̰� �����ϴ�.
//
//T(n) -> O(logY) , �α� ������ �ð� ���⵵

//���� �� ��� : https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
//Dvide and Conquer, �̺�Ž�� ��� : https://www.geeksforgeeks.org/modular-exponentiation-recursive/

#include <iostream>

#define MOD 20091024

using namespace std;

// x^y�� ���� �ڸ����� x^{2^0 * bit} * ... * x^{2^(k-1) * bit} * x^{2^k * bit} ������ ���ذ���.
long long getModularExp(long long x, int y) {
	long long ret = 1;

	while (y > 0) {
		// bit = 1�� �͸� ����ؾ��Ѵ�. bit = 0�� ��� x^{2^k * 0} = 1
		if (y % 2 == 1) {
			ret = (ret * x) % MOD;
		}

		// y �� x�� ���� ������ �ݴ��� ������ ���� ���̿� "10����(Y) <-> 2����" ��ȯ�غ��� �ȴ�.
		// ��ȯ�غ��� ó�� 2�� ���� �������� 2������ 2^0 �ڸ� ����� ���� �� �� �ִ�.
		y /= 2;
		x = (x * x) % MOD;		// x *= x % MOD; �Ұ���. bit = 0�� ����� ��� �����÷ο� �ɸ�.
	}

	return ret;
}

int main() {
	int x, y;
	cin >> x >> y;

	if (x == 0 && y == 0) {
		cout << 1;
		return 0;
	}

	cout << getModularExp(x, y);

	return 0;
}