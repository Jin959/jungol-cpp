/*
* https://www.jungol.co.kr/problem/1912
* 
* DFS 탐색만을 생각할 때, 다음의 탐색 시간이 걸려 TLE에 걸린다고 생각할 수 있다.
* O(NM) -> 10^5 * (5 * 10^5) -> 500억
* T(NM) = 500초 
* 
* 그러나 문제구조상 O(NM) 이 오기전에 N개의 방 탐색이 먼저 끝날 수 밖에 없다.
* -> 정렬 된 인접 리스트 adj 를 탐색하기 때문에 N개의 방을 모두 들러보고 바로 종료 시키면 된다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100'000
#define MAXM 500'000

using namespace std;

int n, m;
int used[MAXN + 1];	// 노드(방) 번호 1부터
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
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());	// 중요
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
	// N개의 방을 모두 방문하고 1번 방으로 오면 동현이는 탐색을 끝낸다.
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

	// 시작 노드(방)은 무조건 1번방
	setStart();
	dfs(1);

	int sz = hist.size();
	for (int i = 0; i < sz; i++) cout << hist[i] << ' ';

	return 0;
}