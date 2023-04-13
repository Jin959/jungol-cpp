#include <iostream>
#include <string>

using namespace std;

int n;

long long factorial(int lv) {
	// base condition
	if (lv == 1) {
		cout << "1! = 1" << endl;
		return 1;
	}

	cout << lv << "! = " << lv << " * " << lv - 1 << '!' << endl;
	return lv * factorial(lv - 1);	
}

int main() {
	cin >> n;
	
	cout << factorial(n);

	return 0;
}