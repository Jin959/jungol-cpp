/*
* 3000���� ����� �����ϱ� ������ DFS �� �ذ��� �� ����.
* �� ������ ���� �κ� ����(Optimal Substructure)�� ã�ƾ� �Ѵ�.
*	DT[i] = max(stair[i] + stair[i - 1] + DT[i - 3], stair[i] + DT[i - 2]);
*/
#include <iostream>
#include <algorithm>

#define MAXN 3000

using namespace std;

int n, score, max_score;
int DT[MAXN], stair[MAXN];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}
}

int main() {
	input();

	DT[0] = stair[0];
	DT[1] = stair[0] + stair[1];
	DT[2] = max(stair[2] + stair[0], stair[2] + stair[1]);

	for (int i = 3; i < n; i++) {
		DT[i] = max(stair[i] + stair[i - 1] + DT[i - 3], stair[i] + DT[i - 2]);
	}

	cout << DT[n - 1];

	return 0;
}