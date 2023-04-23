/*
* ��ǥ���� Ȱ�� ���� ����(Activity Selection Prob)
* 
* Ȱ�� ���� ������ ���� ���� �Ʒ� �ִ�/�ּ� Ȱ�� ������ ���ϴ� �����̴�.
* 1. "����"�� "��" �ð��� n�� �־�����.
* 2. �ϳ��� ��ü�� �ϳ��� Ȱ���� �����Ѵ�.
* 
* �ذ�
* 1. �ִ�/�ּҿ� �°� "��"�� ��������/�������� �����Ѵ�. ��Ȳ�� ���� �ٸ�.
* 2. ù��° Ȱ��(�迭�� �ε����� ī����)�� �켱 ������ ���´�.
* 3. ���� ��ü�� "��" < ���� ��ü�� "����" �� �� ���ذ���.
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

	// 1. "��"�� ���� �Ѵ�.
	sort(meetings.begin(), meetings.end(), cmp);	

	// 2. �ϳ��� ���Ѵ�.
	ans.push_back(meetings[0]);
	int idx = 0;

	// 3. ���ǿ� ���� ���ذ���.
	// �� ȸ�ǿ��� ���۽ð��� ����ð��� ���� ���� �־����� �ʴ´�.
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