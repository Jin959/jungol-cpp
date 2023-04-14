#include <iostream>
#include <string>

using namespace std;

string bowl;
int cnt;
char prev_bowl;
char now_bowl;

void measure() {
	int sz = bowl.size();
	cnt = 10;
	prev_bowl = bowl[0];
	for (int i = 1; i < sz; i++) {
		now_bowl = bowl[i];
		if (now_bowl == prev_bowl) {
			cnt += 5;
		}
		else {
			cnt += 10;
		}
		prev_bowl = bowl[i];
	}
}

int main() {
	cin >> bowl;

	measure();

	cout << cnt;

	return 0;
}