#include <iostream>
#include <string>

using namespace std;

string str;

// KOIOIOI
int cntStr(string target) {
	int s = -1;
	int cnt = 0;
	while (1) {
		s = str.find(target, s + 1);
		if (s == -1) break;
		cnt++;
	}
	return cnt;
}

int main() {
	cin >> str;

	int koi = cntStr("KOI");
	int ioi = cntStr("IOI");

	cout << koi << endl << ioi;

	return 0;
}