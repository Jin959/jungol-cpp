/*
* ������ ��(��Ȳ)�� ��� ������ ���� �����Ѵ�.
*/
#include <iostream>

#define MAXN 100000 // 1 <= N

using namespace std;

int DT[MAXN + 1];

long long dfs(int lv) {
	if (DT[lv] != 0) {
		return DT[lv];
	}

	// ��ȭ��
	return DT[lv] = (2 * dfs(lv - 2) + dfs(lv - 1)) % 20100529;
}

int main() {
	int n; 
	cin >> n;

	// ����
	DT[1] = 1;
	DT[2] = 3;

	cout << dfs(n);

	return 0;
}