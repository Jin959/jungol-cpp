#include <iostream>

#define MAXN 100000

using namespace std;

int DT[MAXN + 1];

int main() {
	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++) {
		// 초항
		if (i == 1 || i == 2) {
			DT[i] = 1;
			continue;
		}

		// 점화식
		DT[i] = (DT[i - 1] + DT[i - 2]) % (int)(10e8 + 7);
	}
	
	cout << DT[n] << endl;

	return 0;
}
