// �� �� ���� ���谡 �����Ѵ�. �ִ�ȭ <-> �ּ�ȭ

#include <iostream>

using namespace std;

struct Coin {
	int quantity;
	int n;
};

Coin coins[6];
int used[6];
int w;
int cnt;

void input() {
	cin >> w;
	int q = 500 * 2;
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			q = coins[i].quantity = q / 2;
		}
		else {
			q = coins[i].quantity = q / 5;
		}
		cin >> coins[i].n;

	}
}

void print() {
	cout << cnt << endl;
	for (int i = 0; i < 6; i++) {
		cout << used[i] << ' ';
	}
}

int main() {
	input();

	int tmp_w, tmp_n;
	for (int i = 5; i > 0; i--) {
		tmp_w = w;
		tmp_n = coins[i].n;
		while (1) {
			tmp_w -= coins[i].quantity * tmp_n;
			if (tmp_w % coins[i - 1].quantity == 0) {
				w = tmp_w;
				used[i] = tmp_n;
				cnt += tmp_n;
				break;
			}
			tmp_w = w;
			tmp_n--;
		}
		if (w == 0) break;
	}

	// ��� �������� �������ε� ��Ȯ�� ���ǰ��� �� �� ���� ���� �Է����� �־����� �ʴ´�. ������ 500
	cnt += tmp_n = w / coins[0].quantity;
	used[0] = tmp_n;
	
	print();

	return 0;
}