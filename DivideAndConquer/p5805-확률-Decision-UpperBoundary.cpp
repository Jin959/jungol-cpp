// 윗면만 나온다고 했을 떄, 얼만큼 더 던져야 z가 변하는지 출력
// 얼만큼 더던져야 z 가 변하냐는 말은 z 가 딱 변할 때를 묻는 것과 같다.
// 즉, upper boundary의 최소값을 찾는 문제이다.

/*
in

1000000000 989999999

out

100
*/

#include <iostream>

#define MAXX 1'000'000'000

using namespace std;

long long x, y, z; // 동전을 던진 수, 윗면이 나온수, 윗면이 나온 확률

void input() {
	cin >> x >> y;
	z = (y * 100) / x;
}

long long getRate(int mid) {
	return ((y + mid) * 100) / (x + mid);
}

int main() {
	input();

	int lb = 0, ub = MAXX;
	int mid;
	int new_rate;
	while (1) {
		if (lb + 1 == ub) break;	// 딱 만날때 종료.
		
		mid = (lb + ub) / 2;

		new_rate = getRate(mid);

		if (new_rate <= z) {		// 아직 확률이 안변하는 구간
			lb = mid;
		}
		else {
			ub = mid;
		}
	}

	if (getRate(ub) == z) cout << -1;
	else cout << ub;

	return 0;
}