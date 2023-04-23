/*
* 대표적인 활동 선택 문제(Activity Selection Prob)
* 
* 활동 선택 문제는 다음 조건 아래 최대/최소 활동 개수를 구하는 문제이다.
* 1. "시작"과 "끝" 시간이 n개 주어진다.
* 2. 하나의 개체가 하나의 활동만 수행한다.
* 
* 해결
* 1. 최대/최소에 맞게 "끝"을 내림차순/오름차순 정렬한다. 상황에 따라 다름.
* 2. 첫번째 활동(배열의 인덱스와 카운팅)을 우선 선택해 놓는다.
* 3. 이전 개체의 "끝" < 다음 개체의 "시작" 일 때 택해간다.
*/



#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 500

using namespace std;


struct Meeting {
	int num;
	int start, end;
};

bool cmp(Meeting l, Meeting r) {
	if (l.end < r.end) return true;
	else return false;
}

int n;
vector<Meeting> meetings;
vector<Meeting> ans;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		Meeting m;
		cin >> m.num >> m.start >> m.end;
		meetings.push_back(m);
	}
}

void print() {
	int sz = ans.size();
	cout << sz << endl;

	for (int i = 0; i < sz; i++) {
		cout << ans[i].num << ' ';
	}
}

int main() {
	input();

	// 1. "끝"을 정렬 한다.
	sort(meetings.begin(), meetings.end(), cmp);	

	// 2. 하나를 택한다.
	ans.push_back(meetings[0]);
	int idx = 0;

	// 3. 조건에 맞춰 택해간다.
	// 한 회의에서 시작시간과 종료시간이 같은 경우는 주어지지 않는다.
	int sz = meetings.size();
	for (int i = 1; i < sz; i++) {
		if (ans[idx].end <= meetings[i].start) {
			ans.push_back(meetings[i]);
			idx++;
		}
	}

	print();

	return 0;
}