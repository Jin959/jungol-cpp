/*
* 3000개의 계단이 존재하기 때문에 DFS 로 해결할 수 없다.
* 이 문제의 최적 부분 구조(Optimal Substructure)를 찾아야 한다.
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