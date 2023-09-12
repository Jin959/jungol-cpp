#include <iostream>
#include <string>

using namespace std;

char dat[200];
string encrypt, decrypt;

void input() {
	string tmp;
	cin >> tmp;
	int sz = tmp.size();
	for (int i = 0; i < sz; i++) {
		dat['a' + i] = tmp[i];
	}

	do {
		cin >> tmp;
		encrypt += tmp;
		encrypt += ' ';
	} while (getc(stdin) == ' ');
}

int main() {
	input();

	int sz = encrypt.size();
	char word;
	
	// decrypt
	for (int i = 0; i < sz; i++) {
		word = encrypt[i];

		if ('A' <= word && word <= 'Z') word = dat[word + ('a' - 'A')] - ('a' - 'A');
		else if ('a' <= word && word <= 'z') word = dat[word];

		decrypt.push_back(word);
	}

	cout << decrypt;

	return 0;
}