// Ȱ�� ����

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

// �� ���� ���ؿ� ���� Line 155~165 �κп���  ���� ���̽��� �ɸ��� �� ������ �ݷʸ� ��ã�ڴ�.
// 95%���� �ɸ�
//bool comp(Flower l, Flower r) {
//	return l.bloom < r.bloom;
//}

// 82%���� �ɸ�
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

		//���� ���� ���� ���� �Ǵ� �� �� ���� �ʰ� ���� ��
		// �� �ݺ����� day�� ���� ���ؿ� ���� �޶�����.
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