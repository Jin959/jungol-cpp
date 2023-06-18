/*
* �� ������ ��� Top-Down ���� �ذ��Ϸ� �� ��� ���������� �� �ۿ� ����.
* �׸���, ������ ���� �б� ���� DT�� �߰��ϸ�(�� �߰�) �������� ���� �� �ִ�.
* 
* ���ڸ� �� ī�忡 ���ؼ� �ٸ� DT(�Ǵ� ��)�� ����� ���� ����ϰ�
* ���� ��(���ڸ� �� ī��)�� ���� ���踦 ã�´�.
* 
* References
* https://mygumi.tistory.com/291
* https://dalseoin.tistory.com/entry/%EB%B0%B1%EC%A4%80-%ED%8C%8C%EC%9D%B4%EC%8D%AC-2591-%EC%88%AB%EC%9E%90%EC%B9%B4%EB%93%9C
*/
#include <iostream>
#include <string>

#define MAXN 40

using namespace std;

// DT[1][i] = (���ڸ� �� ī��� �� �� ����� ��), DT[2][i] = (���ڸ����� ���ڸ� �� ī��� �� �� ����� ��)
int DT[3][MAXN];
string n;

int main() {
	cin >> n;
	int sz = n.size();

	DT[1][0] = 1; // ����
	for (int i = 1; i < sz; i++) {
		int card = stoi(n.substr(i - 1, 2));	// ���ڸ� ���� ���ڸ� �� ����
		if (n[i] == '0') {
			//DT[1][i] = DT[1][i - 1] + DT[2][i - 1];		// n[i]�� '0' �̸� ���� �ڸ� ī�� �Ұ�
			if (10 <= card && card <= 34) {
				DT[2][i] = DT[1][i - 1];
			}
		}
		else {
			DT[1][i] = DT[1][i - 1] + DT[2][i - 1];
			if (10 <= card && card <= 34) DT[2][i] = DT[1][i - 1];		//  n[i - 1 : i] = 09, 71, 77 �Ұ�, 22 ����
		}
	}

	cout << DT[1][sz - 1] + DT[2][sz - 1];
}