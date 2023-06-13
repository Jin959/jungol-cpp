//활동 선택 문제
//
//빨리 내릴 수 있는 것을 우선적으로 택해야한다. 그래야 많은 박스를 나를 수 있다.
//날짜 순으로 순회하면서 트럭을 채우는 것이 아니라 정렬 자료 순으로 탐색

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 2000

using namespace std;

// 공간 복잡도 (4 * 3) * 10000 = 120'000 = 0.12 MB
struct Data {
	int from, to, box;

	bool operator< (Data data) {
		if (this->to < data.to) return true;
		if (this->to > data.to) return false;
		if (this->from < data.from) return true;
		return false;
	}
};

int n, c, m; // 마을 수, 트럭 박스 용량, 데이터 수
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

		// 구간 중 최소인 여유 공간 만큼만 더 실을 수 있다.
		min_r = c;
		for (int i = data.from; i < data.to; i++) {
			int rest = c - loaded[i];
			if (min_r > rest) {
				min_r = rest;
			}
		}

		// 여유공간이 넉넉하면 다 싣는다.
		load = min(min_r, data.box);

		total += load;

		for (int i = data.from; i < data.to; i++) {
			loaded[i] += load;
		}
	}

	cout << total;

	return 0;
}