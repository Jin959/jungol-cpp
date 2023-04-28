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

	// ��ȭ��, �����غ��� �Ǻ���ġ ������ ��.
	return DT[lv] = dfs(lv - 1) + dfs(lv - 2);
}

int main() {
	input();
	// ��� ������
	if (n == m) {
		cout << 1;
		return 0;
	}
	
	// ������ ������ ����� ���� ���� ���� ���ϸ� �� ����� ��
	int ans = 1;
	int start = 1, end;
	for (int i = 0; i < m; i++) {
		// �߿�
		if (fix[i] == start) {
			start++;
			continue;
		}
		
		end = fix[i] - 1;
		//����
		DT[start] = 1;
		DT[start + 1] = 2;

		ans *= dfs(end);

		start = end + 2;
	}

	// ������ ����� ���� ������ �������� n - 2�� ��� ������ �Ѵ�. start = end + 2
	if (start < n) {
		DT[start] = 1;
		DT[start + 1] = 2;
		ans *= dfs(n);
	}

	cout << ans;

	return 0;
}