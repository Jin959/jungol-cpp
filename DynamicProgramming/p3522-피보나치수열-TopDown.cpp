// N <= 100000 으로 재귀 만으로는 구할 수는 없다.

/*
* DP의 조건
* 
* 1. 최적 부분 구조를 띈다. f(n) 의 해는 f(n-1), f(n-2)의 해를 포함한다.
* 2. Overlapping SubProblem. 노드 정보나 누적정보나 어떤 형태로든 재참조 해야하는 f(n)들이 존재한다.
*    - Greedy와의 차이
*/

/*
* Top Down
* 
* 한번 방문한 것에 대해 기록하는 것이다.
* 한번 방문한 것에 대해서는 재연산하지 않는다. 참조만 한다.
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

	// 점화식
	return DT[lv] = (dfs(lv - 1) + dfs(lv - 2)) % (int)(10e8 + 7);
}

int main() {
	int n;
	cin >> n;

	// 초항
	DT[2] = DT[1] = 1;
	cout << dfs(n);

	return 0;
}