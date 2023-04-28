// N <= 100000 ���� ��� �����δ� ���� ���� ����.

/*
* DP�� ����
* 
* 1. ���� �κ� ������ ���. f(n) �� �ش� f(n-1), f(n-2)�� �ظ� �����Ѵ�.
* 2. Overlapping SubProblem. ��� ������ ���������� � ���·ε� ������ �ؾ��ϴ� f(n)���� �����Ѵ�.
*    - Greedy���� ����
*/

/*
* Top Down
* 
* �ѹ� �湮�� �Ϳ� ���� ����ϴ� ���̴�.
* �ѹ� �湮�� �Ϳ� ���ؼ��� �翬������ �ʴ´�. ������ �Ѵ�.
*/

#include <iostream>

#define MAXN 100000

using namespace std;

int DT[MAXN + 1];

int dfs(int lv) {
	if (DT[lv] != 0) {
		return DT[lv];
	}

	// base condition
	if (lv == 1) return DT[1];

	// ��ȭ��
	return DT[lv] = (dfs(lv - 1) + dfs(lv - 2)) % (int)(10e8 + 7);
}

int main() {
	int n;
	cin >> n;

	// ����
	DT[2] = DT[1] = 1;
	cout << dfs(n);

	return 0;
}