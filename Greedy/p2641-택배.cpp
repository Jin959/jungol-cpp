//Ȱ�� ���� ����
//
//���� ���� �� �ִ� ���� �켱������ ���ؾ��Ѵ�. �׷��� ���� �ڽ��� ���� �� �ִ�.
//��¥ ������ ��ȸ�ϸ鼭 Ʈ���� ä��� ���� �ƴ϶� ���� �ڷ� ������ Ž��

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 2000

using namespace std;

// ���� ���⵵ (4 * 3) * 10000 = 120'000 = 0.12 MB
struct Data {
	int from, to, box;

	bool operator< (Data data) {
		if (this->to < data.to) return true;
		if (this->to > data.to) return false;
		if (this->from < data.from) return true;
		return false;
	}
};

int n, c, m; // ���� ��, Ʈ�� �ڽ� �뷮, ������ ��
vector<Data> datas;
int loaded[MAXN + 1];
int total;

void input() {
	cin >> n >> c >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		datas.push_back({a, b, c});
	}
}

int main() {
	input();

	sort(datas.begin(), datas.end());

	int load, min_r;
	for (Data data : datas) {

		// ���� �� �ּ��� ���� ���� ��ŭ�� �� ���� �� �ִ�.
		min_r = c;
		for (int i = data.from; i < data.to; i++) {
			int rest = c - loaded[i];
			if (min_r > rest) {
				min_r = rest;
			}
		}

		// ���������� �˳��ϸ� �� �ƴ´�.
		load = min(min_r, data.box);

		total += load;

		for (int i = data.from; i < data.to; i++) {
			loaded[i] += load;
		}
	}

	cout << total;

	return 0;
}