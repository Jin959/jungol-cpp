#include <iostream>
#include <string>

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;

	while (1) {
		int idx = S.find(T, 0);
		if (idx == -1) break;
		S.erase(idx, T.size());
	}

	cout << S;

	return 0;
}