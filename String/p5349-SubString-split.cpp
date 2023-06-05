#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> stack;

void input();
void print();

int main() {
	input();

	// str = "Jungol is the best "
	int s = 0;
	int e = 0;
	int sz = 0;
	string tmp;
	while (1) {
		e = str.find(" ", s);
		if (e == -1) break;

		sz = e - s;
		tmp = str.substr(s, sz);
		stack.push_back(tmp);

		s = e + 1;
	}

	print();

	return 0;
}

void input() {
	string tmp;
	do {
		cin >> tmp;
		str += tmp += ' ';
	} while (getc(stdin) == ' ');
	//str.push_back(' ');
}

void print() {
	int ssz = stack.size();
	for (int i = ssz - 1; i >= 0; i--) {
		if (i % 2 == 1) {
			cout << stack.back() << ' ';
		}
		stack.pop_back();
	}
}