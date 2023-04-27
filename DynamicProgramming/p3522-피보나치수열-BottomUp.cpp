#include <iostream>

#define MAXN 100000

using namespace std;

int DT[MAXN + 1];

int main() {
	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == 1 || i == 2) {
			DT[i] = 1;
			continue;
		}
		DT[i] = (DT[i - 1] + DT[i - 2]) % (int)(10e8 + 7);
	}
	
	cout << DT[n] << endl;

	return 0;
}
