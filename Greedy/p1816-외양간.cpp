// 판자 한개로만 가리면 제일 긴 경우(해와 정반대 되는 경우)라는 것을 파악해야 설계를 해나갈 수 있었다.
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXS 200

using namespace std;

int M, S, C;
vector<int> cows;
int len;
int dist[MAXS];

void init() {
	cin >> M >> S >> C;
	int tmp;
	for (int i = 0; i < C; i++) {
		cin >> tmp;
		cows.push_back(tmp);
	}
}

void makeDist() {
	for (int i = 1; i < C; i++) {
		dist[i] = cows[i] - cows[i - 1] - 1;
	}
}

// 1개의 판자로만 만든 제일 긴 길이에서 긴 간격 순으로 판자를 자른다.
void measureGreedy() {
	len = *(cows.end() - 1) - *cows.begin() + 1;
	int cnt = 1;
	for (int i = 0; i < C; i++) {
		if (cnt >= M) break;
		len -= dist[i];
		cnt++;
	}
}

int main() {
	init();

	if (M >= C) {
		cout << C;
		return 0;
	}

	// 정렬하고 길이를 재어야한다.
	sort(cows.begin(), cows.end());
	makeDist();
	sort(dist, dist + S, greater<int>());

	measureGreedy();

	cout << len;

	return 0;
}