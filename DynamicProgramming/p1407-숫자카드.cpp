/*
* 0 이 있는 예외

146902336

0

7145910388927205891

4

110

2
*/

#include <iostream>
#include <string>

#define MAX_LEN 40

using namespace std;

string n;
int DT[MAX_LEN];

int dfs(int pos) {
	if (DT[pos] != 0) {
		return DT[pos];
	}

	return DT[pos] = dfs(pos - 1) + dfs(pos - 2);
}

int main() {
	cin >> n;
	DT[0] = 1;
	DT[1] = 2;

	if (n.size() == 1) {
		cout << 1;
		return 0;
	}

	int n_sz = n.size();
	int ans = 1;
	int card, idx = 0;
	int last = 0;
	bool impossible = false;
	for (int i = 0; i < n_sz - 1; i++) {
		card = stoi(n.substr(i, 2));
		if (n[i + 1] == '0') { // 예외 0, 40, 50, 60 ...
			if (card > 34) {
				impossible = true;
				break;
			}
			else {
				ans *= dfs(i - idx);
				idx = i + 2;
				i++;
				if (idx >= n_sz) { // 0이 끝자리일 경우 , 110 2
					ans -= 1; // 마자막 카드로 0을 고를 수 없다.
					cout << ans;
					return 0;
				}
			}
		}
		if (card > 34) {
			ans *= dfs(i - idx);
			idx = i + 1;
		}
		if (i == n_sz - 2) {
			last = (i + 1);
		}
	}

	if (impossible) {
		cout << 0;
		return 0;
	}

	ans *= dfs(last - idx);

	cout << ans;

	return 0;
}