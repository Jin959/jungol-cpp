#include <iostream>

#define MAXN 40

using namespace std;

int n, m;
int DT[MAXN + 1];
int fix[MAXN];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> fix[i];
	}
}

int dfs(int lv) {
	if (DT[lv] != 0) {
		return DT[lv];
	}

	// 점화식, 나열해보면 피보나치 수열이 됨.
	return DT[lv] = dfs(lv - 1) + dfs(lv - 2);
}

int main() {
	input();
	// 모두 고정석
	if (n == m) {
		cout << 1;
		return 0;
	}
	
	// 고정석 사이의 경우의 수를 각각 구해 곱하면 총 경우의 수
	int ans = 1;
	int start = 1, end;
	for (int i = 0; i < m; i++) {
		// 중요
		if (fix[i] == start) {
			start++;
			continue;
		}
		
		end = fix[i] - 1;
		//초항
		DT[start] = 1;
		DT[start + 1] = 2;

		ans *= dfs(end);

		start = end + 2;
	}

	// 마지막 경우의 수는 마지막 고정석이 n - 2인 경우 까지만 한다. start = end + 2
	if (start < n) {
		DT[start] = 1;
		DT[start + 1] = 2;
		ans *= dfs(n);
	}

	cout << ans;

	return 0;
}