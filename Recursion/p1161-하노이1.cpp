/*
* 주의 : 재귀 함수의 파라미터를 "기둥 1 -> 기둥 3" 식이 아니라 "출발 기둥 -> 목적지 기둥" 식으로 생각하기
*	재귀로 부분 문제로 파고들었을 때, 출발지와 목적지 등이 바뀌기 때문이다.
* 
* n개의 고리를 옮겨야한다는 것은 다음과 같이 귀납적으로 생각할 수 있다.
* 
* 1. (n-1)개 원판 : 출발 기둥 -> 경유 기둥
* 2. 제일 넓은 원판 : 출발 기둥 -> 목적지 기둥
* 3. (n-1) 개의 원판 : 경유 기둥 -> 목적지 기둥
* 
* 원판 n개 모두를 옮긴다는 것은 이것을 n 번 반복하는 것과 같다.
* 과정 2 전후로 (n-1)개 원판을 출발지와 목적지를 변경하면서 두번 이동 시키는 부분 문제를 포함한다.
* 
* 출력 :  “원판번호 : 이동 전 기둥번호 -> 이동 후 기둥번호” 형식
* 
* https://shoark7.github.io/programming/algorithm/tower-of-hanoi
*/

#include <iostream>

#define MAXN 15

using namespace std;

int n;

// 중위 순회
void dfs(int n, int from, int via, int to) {
	if (n == 1) {
		cout << n << " : " << from << " -> " << to << '\n';		// 1 : 1 -> 3
		return;
	}

	dfs(n - 1, from, to, via);
	cout << n << " : " << from << " -> " << to << '\n';
	dfs(n - 1, via, from, to);
}

int main() {
	cin >> n;
	dfs(n, 1, 2, 3);

	return 0;
}