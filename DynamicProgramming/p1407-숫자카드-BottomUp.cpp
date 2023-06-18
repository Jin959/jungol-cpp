/*
* 이 문제의 경우 Top-Down 으로 해결하려 할 경우 비직관적일 수 밖에 없다.
* 그리고, 가능한 조건 분기 별로 DT를 추가하면(행 추가) 조건절을 줄일 수 있다.
* 
* 두자리 수 카드에 대해서 다른 DT(또는 행)에 경우의 수를 기록하고
* 원래 행(한자리 수 카드)과 연관 관계를 찾는다.
* 
* References
* https://mygumi.tistory.com/291
* https://dalseoin.tistory.com/entry/%EB%B0%B1%EC%A4%80-%ED%8C%8C%EC%9D%B4%EC%8D%AC-2591-%EC%88%AB%EC%9E%90%EC%B9%B4%EB%93%9C
*/
#include <iostream>
#include <string>

#define MAXN 40

using namespace std;

// DT[1][i] = (한자리 수 카드로 볼 때 경우의 수), DT[2][i] = (앞자리까지 두자리 수 카드로 볼 때 경우의 수)
int DT[3][MAXN];
string n;

int main() {
	cin >> n;
	int sz = n.size();

	DT[1][0] = 1; // 초항
	for (int i = 1; i < sz; i++) {
		int card = stoi(n.substr(i - 1, 2));	// 앞자리 포함 두자릿 수 추출
		if (n[i] == '0') {
			//DT[1][i] = DT[1][i - 1] + DT[2][i - 1];		// n[i]가 '0' 이면 일의 자리 카드 불가
			if (10 <= card && card <= 34) {
				DT[2][i] = DT[1][i - 1];
			}
		}
		else {
			DT[1][i] = DT[1][i - 1] + DT[2][i - 1];
			if (10 <= card && card <= 34) DT[2][i] = DT[1][i - 1];		//  n[i - 1 : i] = 09, 71, 77 불가, 22 가능
		}
	}

	cout << DT[1][sz - 1] + DT[2][sz - 1];
}