// https://www.jungol.co.kr/problem/1077

/*
* DP의 대표적인 Knapsack 문제이다.
* 무게가 W를 넘지 않으면서 총 물건의 값어치가 최대가 되도록 배낭을 채운다. 배낭에 담은 값어치의 최대값을 출력하라.
* CC(동전 교환) 문제와 유사하다.
* 
* (Knapsack/CC) 둘다 "어떤 단위 들"(물건의 무게, 동전 단위)과 "해당 단위 량의 제한"(배낭의 용량/목표 거스름돈)이 주어질 때,
* 해당 단위 량이 아닌 "다른 량"(물건의 값어치, 동전의 개수)을 최적화(최대화/최소화) 시키는 문제이다.
* 
* 1. CC
* coin 이 아닌 "잔돈 금액"을 idx로 DT 를 사용한다.
* -> 1원 부터 "목표 잔돈 액수"까지 순회하면서
* -> "해당 단위동전 1개 + 해당 동전의 단위 만큼 뺐을때(해당 동전을 1개 사용하기 직전)의 동전 개수"와
*	"지금까지 알아놓은 최소 사용 개수"를 비교한다.
* -> "동전의 개수"를 최소화 한다. (DT[i] 에 담을 값이면서 문제의 목표이다.)
* 
* 2. Knapsack
* "배낭의 무게"를 idx로 DT 를 사용한다.
* -> 무게 1 부터 "배낭의 용량"까지 순회하면서
* -> "해당 무게 단위 물건(item) 1개의 값어치 + 해당 물건의 무게 만큼 뺐을때(해당 물건 1개를 담기 직전)의 값어치"와
*	"지금 까지 알아놓은 최대 값어치"를 비교한다.
* -> "배낭에 담은 값어치"를 최대화 한다. (DT[i] 에 담을 값이면서 문제의 목표이다.)
*/

#include <iostream>
#include <algorithm>

#define MAXN 1000	// 보석, item 개수
#define MAXW 10000	// 배낭의 용량

using namespace std;

struct Item {
	int weight, value;
};

int n, w;
Item item[MAXN];
int DT[MAXW + 1];

void input() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> item[i].weight >> item[i].value;
	}
}

int main() {
	input();

	for (int i = 0; i < n; i++) {
		DT[item[i].weight] = max(DT[item[i].weight], item[i].value);
		for (int j = item[i].weight + 1; j <= w; j++) {
			DT[j] = max(DT[j - item[i].weight] + item[i].value, DT[j]);
		}
	}

	cout << DT[w];

	return 0;
}