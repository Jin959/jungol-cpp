/*
* https://www.jungol.co.kr/problem/4791
* 
* ���� �Լ��� �˱� ����� ���� �����̴�.
* - �׷� �� ���� �ִ��� "��(mid)"�� ��� ���س��� ���Ҷ����� ����Ž������ Ȯ���Ѵ�.
* 
* ���� �Լ��� ���ø��� ���� �˰� �־���� ���� �ִ�.
* 1. �־��� ���� : ������ ������ �ٲ� �� ����. -> ������ ������ �����Ѵ�.
* 
* 2. "�׷��� ���� �ִ�(upper bound)�� �ּ�ȭ(min)�Ѵ�"�� ����
*	"�׷캰 ������ ������ �ִ��� ������ �л� ��Ų��"�� �Ͱ� ����.
*	2���� ���� �ѹ� �� �����ϸ� ��� �׷��� Ȯ�� �� �ʿ䰡 ���ٴ� ���� �����Ѵ�.
*	�ִ��� �л�� ������ �׷��� ���� ����ص��ȴ�.
* 
* 3. M�� �Ű������μ� Ȱ���� ������ �ؾ��Ѵ�.
*	���� �Լ��� �Ű������� M �̴�. M�� �Է� ���� ��ǥ M �� ������ ������ Ȯ���ؾ��Ѵ�.
*	ub = (M=1 �� ��, ���� ��ü�� �ѱ׷��� ��) �̴�. ���� �ִ밪(upper bound)�� �ȴ�.
*	lb = (M=N �� ��, ���� �Ѱ��� �ѱ׷��� ��) �̴�. ���� ū ���� ������ ���� �ּڰ�(lower bound)�� �ȴ�.
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

// �׷캰 ������ ������ �ִ��� ������ �л� ��Ű�� �Ͱ� ���� ������ �����ϴ�.
// ��� ��츦 ���°� �ƴ϶�, �ִ��� �л� �ɶ��� Ȯ���ϴ� ������ ����.
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
		mid = (lb + ub) / 2;			// mid �� �׷� �� ���� �ִ밪���� ������ ���̴�.
		if (getGroupCnt(mid) > m) {		// �׷��� �� group_cnt �� ���̱� ���� �ִ밪�� �÷����Ѵ�.
			lb = mid;
		}
		else {							// �׷��� �� group_cnt �� ���̱� ���� �ּڰ��� ������Ѵ�.
			ub = mid;
		}
	}

	// Edge Case, ���� ����� �̺�Ž���� lb, rb ũ�ν� ���� ���� �ʴ´�. ub �� �����ϵ��� �Ǿ��ִ�.
	// ��, ��ǥ �׷� ���� ���� ����ŭ(n��) �϶��ų� ���� ū ���� �Ѱ��� ���� �� �ִ»�Ȳ�϶�,
	if (max_bead == lb) {	// lb �� �ȿ�����.
		cout << lb;
		return 0;
	}
	cout << ub;

	return 0;
}