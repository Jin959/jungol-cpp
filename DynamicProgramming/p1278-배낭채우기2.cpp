// https://www.jungol.co.kr/problem/1278

/*
* 나와 같은 질문들
* 
* https://www.acmicpc.net/board/view/47400
* 제가 지금 한 물건을 여러번 담는 상황에 놓인 것 같은데 이걸 어떻게 고치죠..?
* 한 물건을 두 번 넣는 이유는 간단합니다.
* DP[i][j+'A의 무게']가 바뀌기 전에 DP[i][j]가 바뀌었기 때문입니다.
* 따라서 다음과 같은 대안들을 생각해볼 수 있겠네요.
* 
* 1. DP[i]와 길이가 같은 새로운 배열 new 를 만들고 A를 넣은 방법을 계산해서 new를 전부 갱신한 후에 DP[i]에 new로 대입한다.
* 2. 물건들의 무게가 전부 양수임을 이용하여, DP[i][j]를 j가 큰 것부터 계산한다.
* 
* 나는 2번 방법으로 해결했다.
* 
* https://www.acmicpc.net/board/view/85632
* 
* 
* 
* # DP 가 채워지는 순서
* 
* 예제
* 2 10
* 6 5
* 5 3
* 
* 1. j가 증가할 경우
* 
*	i=0이 끝난 후
* 0 0 0 0 0 0 5 5 5 5 5
*	i=1이 끝난 후
* 0 0 0 0 0 3 5 5 5 5 6
* 
* 2. j가 감소할 경우
* 
*	i=0이 끝난 후
* 0 0 0 0 0 0 5 5 5 5 5
*	i=1이 끝난 후
* 0 0 0 0 0 3 5 5 5 5 5
*/

#include <iostream>
#include <algorithm>

#define MAXN 1000
#define MAXW 10000

using namespace std;

struct Item {
	int value, weight;
};

int n, w;
Item item[MAXN];
int DT[MAXW];

void input() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> item[i].weight >> item[i].value;
	}
}

int main() {
	input();

	for (int i = 0; i < n; i++) {
		for (int j = w; j >= item[i].weight; j--) {
			DT[j] = max(DT[j - item[i].weight] + item[i].value, DT[j]);
		}
	}

	cout << DT[w];

	return 0;
}