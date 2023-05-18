#include <iostream>
#include <vector>

#define MAXN 500'000
#define MAXQ 500'000

using namespace std;

int n, q;
vector<int> v(MAXN);
vector<int> query(MAXQ);

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> query[i];
	}
}

int binarySearch(int t) {
	int l = 0;
	int r = n - 1;
	int mid = -1;
	while (1) {
		mid = (l + r) / 2;

		if (l > r) {
			mid = -1;
			break;
		}
		
		if (v[mid] == t) break;

		if (t < v[mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return mid;
}

int main() {
	input();

	for (int i = 0; i < q; i++) {
		cout << binarySearch(query[i]) << ' ';
	}

	return 0;
}