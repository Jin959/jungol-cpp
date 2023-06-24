//Modular Exponentiation(모듈러 지수) - 거듭제곱 빠르게 구하기
//CLRS 알고리즘 - 31.6 정수론:원소의 거듭제곱 page.983
// 
//모듈러 연산은 순환 성질을 갖으며, 곱셈에 대한 분배 법칙이 성립하기 때문에 나머지를 계속해서 이용하는 풀이가 가능하다.
//
//T(n) -> O(logY) , 로그 지수의 시간 복잡도

//지금 한 방법 : https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
//Dvide and Conquer, 이분탐색 방식 : https://www.geeksforgeeks.org/modular-exponentiation-recursive/

#include <iostream>

#define MOD 20091024

using namespace std;

// x^y를 낮은 자리부터 x^{2^0 * bit} * ... * x^{2^(k-1) * bit} * x^{2^k * bit} 순으로 곱해간다.
long long getModularExp(long long x, int y) {
	long long ret = 1;

	while (y > 0) {
		// bit = 1인 것만 사용해야한다. bit = 0인 경우 x^{2^k * 0} = 1
		if (y % 2 == 1) {
			ret = (ret * x) % MOD;
		}

		// y 와 x의 증감 방향이 반대인 이유는 직접 종이에 "10진수(Y) <-> 2진수" 변환해보면 안다.
		// 변환해보면 처음 2로 나눈 나머지가 2진수의 2^0 자리 수라는 것을 알 수 있다.
		y /= 2;
		x = (x * x) % MOD;		// x *= x % MOD; 불가능. bit = 0이 길어질 경우 오버플로우 걸림.
	}

	return ret;
}

int main() {
	int x, y;
	cin >> x >> y;

	if (x == 0 && y == 0) {
		cout << 1;
		return 0;
	}

	cout << getModularExp(x, y);

	return 0;
}