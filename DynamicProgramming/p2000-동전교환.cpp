// https://www.jungol.co.kr/problem/3521

/*
* DP�� ��ǥ���� CC(Coin Change) �����̴�.
* ��ǥ �ܵ� ���� ���߱� ���� �ּ� ���� ���� ���ض�
* �賶 ä���(Knapsack) ������ �����ϴ�.
* ��� ������ ���鼭 �ּ� ������ ä���Ͽ� ����ȭ ��Ű�� �ȴ�.
* 
* ������ ������ ���� ������谡 �ƴ� �� �ֱ� ������ Ž���� ���� ������ �������� �ʴ´�.
* ��, Greedy�� �Ž����� ������ ���� �ٸ���.
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
int target;	// ���ְ� �ý��� Ÿ�� �ܵ�

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cin >> target;
}

int main() {
	input();
	
	memset(DT, 0x7f, sizeof(DT));	// 0x7F (HEX) = 0111 1111(BIN) , �׸��� int�� 4 bytes
	
	for (int i = 0; i < n; i++) {
		DT[coin[i]] = 1;	// ���� ������ �ش��ϴ� �ݾ��� �ּ� ���� ������ 1�� �̴�.
		for (int j = (coin[i] + 1); j <= target; j++) {
			DT[j] = min(DT[j - coin[i]] + 1, DT[j]);
		}
	}

	if (DT[target] == 0x7f7f7f7f) cout << "impossible";
	else cout << DT[target];

	return 0;
}