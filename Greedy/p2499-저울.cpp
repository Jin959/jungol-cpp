// 수학적 귀납법
/*
* 다음 추의 의 무게가 직전의 무게들과 많이 차이나면 그만큼 가능한 무게의 공백이 생기는 것은 알 수 있다.
* 
* 이 다음부터 직접 손으로 세어보면서 수학적 귀납으로 논증 가능한지 확인해야 풀 수 있다.
* 손으로 센다는 것은 n=1 일때부터 n번째 와 n+1번째의 상황을 비교하는 것을 말하고
* n번째 와 n+1번째의 상황 비교를 통해 a(n) -> a(n+1) 사이의 점화식을 세우는 것이 목표이다.
* 
* 이 문제의 점화식을 구현한 for 문에서 주목할 것은 다음과 같다.
* 
* 1. s + pend[i] : 이번 점화식 (i 번째 루프) 에서 확인할 가능한 무게
* 2. s + pend[i] + 1 : 확인할 가능한 무게(s + pend[i])의 바로 다음 무게
* 3. s + pend[i] + 1 >= pend[i + 1] 이면, 무게 (s + pend[i]) 까지는 측정 가능하다.
*/

#include <iostream>
#include <algorithm>

#define MAXN 1000

using namespace std;

int n;
int pend[MAXN];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pend[i];
	}
}

int main() {
	input();
	sort(pend, pend + n);
	if (pend[0] != 1) {
		cout << 1;
		return 0;
	}

	long long s = 1; // 직전까지의 추로 만들 수 있는 무게
	int min_impossible = -1;
	for (int i = 1; i < n - 1; i++) {
		if (s + pend[i] + 1 < pend[i + 1]) {
			min_impossible = s + pend[i] + 1;
			break;
		}
		s += pend[i];
	}

	if (min_impossible == -1) {
		min_impossible = s + pend[n - 1] + 1;
	}

	cout << min_impossible;

	return 0;
}