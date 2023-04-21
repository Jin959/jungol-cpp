// ���� �Ѱ��θ� ������ ���� �� ���(�ؿ� ���ݴ� �Ǵ� ���)��� ���� �ľ��ؾ� ���踦 �س��� �� �־���.
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

// 1���� ���ڷθ� ���� ���� �� ���̿��� �� ���� ������ ���ڸ� �ڸ���.
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

	// �����ϰ� ���̸� �����Ѵ�.
	sort(cows.begin(), cows.end());
	makeDist();
	sort(dist, dist + S, greater<int>());

	measureGreedy();

	cout << len;

	return 0;
}