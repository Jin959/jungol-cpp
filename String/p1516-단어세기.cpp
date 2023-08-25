/*
* 처리조건
* (1) 입력된 스트링은 글자의 제한은 없다. 즉, 알파벳 대 소문자, 공백, ',' 등도 입력으로 들어 올 수 있다.
* (2) 입력된 문장에서 각 단어사이의 구분은 공백으로 한다.
* (3) 단어에는 공백을 제외한 모든 문자들이 포함된다.
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

// 각 문장 단위로 단어들의 발생 빈도를 오름차순 크기(아스키코드)순으로 출력한다.
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