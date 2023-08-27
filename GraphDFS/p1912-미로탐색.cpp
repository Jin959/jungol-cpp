/*
* https://www.jungol.co.kr/problem/1912
* 
* DFS Ž������ ������ ��, ������ Ž�� �ð��� �ɷ� TLE�� �ɸ��ٰ� ������ �� �ִ�.
* O(NM) -> 10^5 * (5 * 10^5) -> 500��
* T(NM) = 500�� 
* 
* �׷��� ���������� O(NM) �� �������� N���� �� Ž���� ���� ���� �� �ۿ� ����.
* -> ���� �� ���� ����Ʈ adj �� Ž���ϱ� ������ N���� ���� ��� �鷯���� �ٷ� ���� ��Ű�� �ȴ�. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100'000
#define MAXM 500'000

using namespace std;

int n, m;
int used[MAXN + 1];	// ���(��) ��ȣ 1����
vector<int> adj[MAXN + 1];
vector<int> hist;

void input() {
	cin >> n >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
}

void init() {
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());	// �߿�
}

void setStart() {
	hist.push_back(1);
	used[1] = true;
}

bool isEnd() {
	for (int i = 1; i <= n; i++) {
		if (!used[i]) return false;
	}

	return true;
}

void dfs(int now) {
	// N���� ���� ��� �湮�ϰ� 1�� ������ ���� �����̴� Ž���� ������.
	if (isEnd() && now == 1) return;

	for (int nxt : adj[now]) {
		if (used[nxt]) continue;

		used[nxt] = true;
		hist.push_back(nxt);
		dfs(nxt);
	}
}

int main() {
	input();
	init();

	// ���� ���(��)�� ������ 1����
	setStart();
	dfs(1);

	int sz = hist.size();
	for (int i = 0; i < sz; i++) cout << hist[i] << ' ';

	return 0;
}