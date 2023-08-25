/*
* ó������
* (1) �Էµ� ��Ʈ���� ������ ������ ����. ��, ���ĺ� �� �ҹ���, ����, ',' � �Է����� ��� �� �� �ִ�.
* (2) �Էµ� ���忡�� �� �ܾ������ ������ �������� �Ѵ�.
* (3) �ܾ�� ������ ������ ��� ���ڵ��� ���Եȴ�.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Data {
	string key;
	int cnt;
};

// �� ���� ������ �ܾ���� �߻� �󵵸� �������� ũ��(�ƽ�Ű�ڵ�)������ ����Ѵ�.
bool cmp(Data l, Data r) {
	if (l.key < r.key) return true;
	return false;
}

string state;
vector<Data> ans;
unordered_map<string, bool> used;


void getState() {
	string tmp;
	do {
		cin >> tmp;
		state += tmp;
		state.push_back(' ');
	} while (getc(stdin) == ' ');
}

void init() {
	state.clear();
	ans.clear();
	used.clear();
}

void makeAnsList(int s, string tar) {
	int e = 0;
	int cnt = 0;
	while (true) {
		e = state.find(' ', s);
		if (e == -1) break;

		string word = state.substr(s, e - s);
		if (word == tar) cnt++;

		s = e + 1;
	}
	used[tar] = true;
	ans.push_back({ tar, cnt });
}

void countWord() {
	int s = 0, e = 0;
	while (true) {
		e = state.find(' ', s);
		if (e == -1) break;

		string tar = state.substr(s, e - s);
		if (used[tar]) {
			s = e + 1;
			continue;
		}

		makeAnsList(s, tar);
		s = e + 1;
	}
}

void print() {
	sort(ans.begin(), ans.end(), cmp);
	int sz = ans.size();
	for (int i = 0; i < sz; i++) {
		cout << ans[i].key << " : " << ans[i].cnt << endl;
	}
}

int main() {
	while (true) {
		init();
		getState();

		if (state == "END ") break;

		countWord();
		print();
	}

	return 0;
}