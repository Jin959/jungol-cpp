// https://www.jungol.co.kr/problem/1278

/*
* ���� ���� ������
* 
* https://www.acmicpc.net/board/view/47400
* ���� ���� �� ������ ������ ��� ��Ȳ�� ���� �� ������ �̰� ��� ��ġ��..?
* �� ������ �� �� �ִ� ������ �����մϴ�.
* DP[i][j+'A�� ����']�� �ٲ�� ���� DP[i][j]�� �ٲ���� �����Դϴ�.
* ���� ������ ���� ��ȵ��� �����غ� �� �ְڳ׿�.
* 
* 1. DP[i]�� ���̰� ���� ���ο� �迭 new �� ����� A�� ���� ����� ����ؼ� new�� ���� ������ �Ŀ� DP[i]�� new�� �����Ѵ�.
* 2. ���ǵ��� ���԰� ���� ������� �̿��Ͽ�, DP[i][j]�� j�� ū �ͺ��� ����Ѵ�.
* 
* ���� 2�� ������� �ذ��ߴ�.
* 
* https://www.acmicpc.net/board/view/85632
* 
* 
* 
* # DP �� ä������ ����
* 
* ����
* 2 10
* 6 5
* 5 3
* 
* 1. j�� ������ ���
* 
*	i=0�� ���� ��
* 0 0 0 0 0 0 5 5 5 5 5
*	i=1�� ���� ��
* 0 0 0 0 0 3 5 5 5 5 6
* 
* 2. j�� ������ ���
* 
*	i=0�� ���� ��
* 0 0 0 0 0 0 5 5 5 5 5
*	i=1�� ���� ��
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