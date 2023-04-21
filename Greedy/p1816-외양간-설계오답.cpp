#include <iostream>
#include <vector>

#define MAXM 50
#define MAXS 200

using namespace std;

int M, S, C; // 최대 판자수, 총 외양간 수, 소가 있는 외양간
int len_sum, cnt;
vector<int> cows;

void input() {
	cin >> M >> S >> C;
	for (int i = 0; i < C; i++) {
		int tmp;
		cin >> tmp;
		cows.push_back(tmp);
	}
}

int main() {
	input();

	int idx = 0;
	int cnt = 1; // C >= 1 이상이다.
	for (int i = 1; i <= S; i++) {
		if (cnt > M) break;
		if (*(cows.end() - 1) < i) break;

		if (i == cows[idx]) {
			if (idx != 0 && cows[idx] != cows[idx - 1] + 1) {
				cnt++;
			}
			len_sum++;
			idx++;
		}
	}

	cout << len_sum;

	return 0;
}