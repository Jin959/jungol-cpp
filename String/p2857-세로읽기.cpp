#include <iostream>
#include <string>
#include <vector>

#define INPUT_ROW 5

using namespace std;

vector<string> board;
string ans;
int max_len = -21e8;

void input() {
	for (int i = 0; i < INPUT_ROW; i++) {
		cout << max_len;
		string s;
		cin >> s;
		int sz = s.size();
		if (sz > max_len) {
			max_len = sz;
		}
		board.push_back(s);
	}
}

void readDown() {
	for (int x = 0; x < max_len; x++) {
		for (int y = 0; y < INPUT_ROW; y++) {
			if (x >= board[y].size()) continue;
			ans.push_back(board[y][x]);
		}
	}
}

int main() {
	input();
	readDown();

	cout << ans;
}