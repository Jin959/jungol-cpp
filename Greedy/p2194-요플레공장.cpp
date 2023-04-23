// Greedy 라기보다는 그냥 구현, simulation인듯

#include <iostream>
#include <algorithm>

#define MAXN 10000

using namespace std;

struct Data {
	int price, need_lt;
};

int N, S;
Data milk[MAXN];

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> milk[i].price >> milk[i].need_lt;
	}
}

int main() {
	input();

	long long charge = milk[0].price * milk[0].need_lt;
	int min_price;

	for (int i = 1; i < N; i++) {
		min_price = milk[i].price;
		for (int j = 0; j < i; j++) {
			min_price = min(milk[j].price + (i - j) * S, min_price);
		}
		charge += min_price * milk[i].need_lt;
	}

	cout << charge;

	return 0;
}