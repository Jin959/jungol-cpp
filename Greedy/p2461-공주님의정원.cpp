// 활동 선택

#include <iostream>
#include <algorithm>

#define MAXN 100000

using namespace std;

struct Date {
	int month, day;

	bool operator<= (Date date) {
		if (month < date.month) return true;
		else if (month == date.month) {
			if (day <= date.day) return true;
		}
		return false;
	}

	bool operator< (Date date) {
		if (month < date.month) return true;
		else if (month == date.month) {
			if (day < date.day) return true;
		}
		return false;
	}

	bool operator>= (Date date) {
		if (month > date.month) return true;
		else if (month == date.month) {
			if (day >= date.day) return true;
		}
		return false;
	}

	bool operator> (Date date) {
		if (month > date.month) return true;
		else if (month == date.month) {
			if (day > date.day) return true;
		}
		return false;
	}
};

struct Flower {
	Date bloom;
	Date death;
};

int n, cnt;
Flower flws[MAXN];
Date last_death;
Date lb = { 3, 1 };
Date ub = { 11, 30 };
bool impossible = false;

// 이 정렬 기준에 따라 Line 155~165 부분에서  엣지 케이스가 걸리는 것 같은데 반례를 못찾겠다.
// 95%에서 걸림
//bool comp(Flower l, Flower r) {
//	return l.bloom < r.bloom;
//}

// 82%에서 걸림
//bool comp(Flower l, Flower r) {
//	if (l.bloom < r.bloom) return true;
//	if (l.bloom > r.bloom) return false;
//
//	return l.death > r.death;
//}

bool comp(Flower l, Flower r) {
	if (l.bloom < r.bloom) return true;
	if (l.bloom > r.bloom) return false;

	return l.death < r.death;
}

void input() {
	cin >> n;

	Date max = { 1, 1 }, min = { 12, 31 };
	for (int i = 0; i < n; i++) {
		cin >> flws[i].bloom.month >> flws[i].bloom.day
			>> flws[i].death.month >> flws[i].death.day;

		Flower flw = flws[i];

		if (flw.bloom < min) {
			min = flw.bloom;
		}
		if (flw.death > max) {
			max = flw.death;
		}
	}

	if (min > lb || max <= ub) {
		impossible = true;
	}
}

int setBegin() {
	int idx = 0;
	Flower begin_flw = flws[0];
	for (int i = 1; i < n; i++) {
		Flower flw = flws[i];
		if (flw.bloom > lb) break;
		if (flw.death > begin_flw.death) {
			idx = i;
		}
	}
	return idx;
}

int main() {
	input();
	if (impossible) {
		cout << 0;
		return 0;
	}

	sort(flws, flws + n, comp);

	int idx = setBegin();
	last_death = flws[idx].death;
	cnt = 1;

	for (int i = idx + 1; i < n; i++) {
		if (last_death > ub) break;
		Flower flw = flws[i];

		if (flw.death <= last_death) continue;
		
		if (flw.bloom > last_death) {
			impossible = true;
			break;
		}

		//현재 꽃이 지기 전에 피는 꽃 중 가장 늦게 지는 꽃
		// 이 반복문이 day의 정렬 기준에 따라 달라진다.
		Date max_death = flw.death;
		for (int j = i + 1; j < n; j++) {
			if (flws[j].bloom > last_death) break;
			if (flws[j].death > max_death) {
				max_death = flws[j].death;
				i = j;
			}
		}
		last_death = max_death;
		cnt++;
	}

	if (impossible) {
		cout << 0;
		return 0;
	}
	cout << cnt;

	return 0;
}