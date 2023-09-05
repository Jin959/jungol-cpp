/*
* https://www.jungol.co.kr/problem/4791
* 
* 결정 함수를 알기 어려운 결정 문제이다.
* - 그룹 중 합의 최댓값은 "얼마(mid)"다 라고 정해놓고 정할때마다 이진탐색으로 확인한다.
* 
* 결정 함수를 떠올리기 위해 알고 있어야할 것이 있다.
* 1. 주어진 조건 : 구슬의 순서를 바꿀 수 없다. -> 구슬은 순서를 유지한다.
* 
* 2. "그룹의 합의 최댓값(upper bound)을 최소화(min)한다"는 것은
*	"그룹별 구슬의 개수를 최대한 같도록 분산 시킨다"는 것과 같다.
*	2번에 대해 한번 더 생각하면 모든 그룹을 확인 할 필요가 없다는 것을 내포한다.
*	최대한 분산된 개수의 그룹일 때만 고려해도된다.
* 
* 3. M을 매개변수로서 활용할 생각을 해야한다.
*	결정 함수의 매개변수는 M 이다. M을 입력 받은 목표 M 이 가능할 떄인지 확인해야한다.
*	ub = (M=1 일 때, 구슬 전체가 한그룹일 때) 이다. 값이 최대값(upper bound)이 된다.
*	lb = (M=N 일 때, 구슬 한개가 한그룹일 때) 이다. 가장 큰 값의 구슬의 값이 최솟값(lower bound)이 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> bead_vec;
int lb, ub, max_bead;

void input() {
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		bead_vec.push_back(tmp);

		lb = max(lb, tmp);
		ub += tmp;
	}
	max_bead = lb;
}

// 그룹별 구슬의 개수를 최대한 같도록 분산 시키는 것과 같기 때문에 가능하다.
// 모든 경우를 보는게 아니라, 최대한 분산 될때만 확인하는 행위와 같다.
int getGroupCnt(int mid) {
	int sum = 0;
	int group_cnt = 1;
	for (int i = 0; i < n; i++) {
		sum += bead_vec[i];
		if (sum > mid) {
			sum = bead_vec[i];
			group_cnt++;
		}
	}
	
	return group_cnt;
}

int main() {
	input();

	int mid;
	while (true) {
		if (lb + 1 == ub) break;
		mid = (lb + ub) / 2;			// mid 는 그룹 중 합의 최대값으로 상정한 값이다.
		if (getGroupCnt(mid) > m) {		// 그룹의 수 group_cnt 를 줄이기 위해 최대값을 올려야한다.
			lb = mid;
		}
		else {							// 그룹의 수 group_cnt 를 높이기 위해 최솟값을 낮춰야한다.
			ub = mid;
		}
	}

	// Edge Case, 내가 사용한 이분탐색은 lb, rb 크로스 오버 되지 않는다. ub 만 리턴하도록 되어있다.
	// 즉, 목표 그룹 수가 구슬 수만큼(n개) 일때거나 가장 큰 구슬 한개로 남길 수 있는상황일때,
	if (max_bead == lb) {	// lb 가 안움직임.
		cout << lb;
		return 0;
	}
	cout << ub;

	return 0;
}