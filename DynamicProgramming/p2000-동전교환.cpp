// https://www.jungol.co.kr/problem/3521

/*
* DP의 대표적인 CC(Coin Change) 문제이다.
* 목표 잔돈 수를 맞추기 위한 최소 동전 수를 구해라
* 배낭 채우기(Knapsack) 문제와 유사하다.
* 모든 단위를 돌면서 최소 개수를 채택하여 최적화 시키면 된다.
* 
* 동전의 단위가 서로 배수관계가 아닐 수 있기 때문에 탐용적 선택 조건을 만족하지 않는다.
* 즉, Greedy의 거스름돈 문제와 조금 다르다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 10
#define MAXW 64000

using namespace std;

int n;
int coin[MAXN];
int DT[MAXW + 1];
int target;	// 내주고 시싶은 타겟 잔돈

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cin >> target;
}

int main() {
	input();
	
	memset(DT, 0x7f, sizeof(DT));	// 0x7F (HEX) = 0111 1111(BIN) , 그리고 int는 4 bytes
	
	for (int i = 0; i < n; i++) {
		DT[coin[i]] = 1;	// 단위 동전에 해당하는 금액의 최소 동전 개수는 1개 이다.
		for (int j = (coin[i] + 1); j <= target; j++) {
			DT[j] = min(DT[j - coin[i]] + 1, DT[j]);
		}
	}

	if (DT[target] == 0x7f7f7f7f) cout << "impossible";
	else cout << DT[target];

	return 0;
}