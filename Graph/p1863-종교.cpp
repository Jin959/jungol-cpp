//Union-Find
// Forest에서 Tree의 개수를 구하는 것과 같다.
// 중요 : 같은 그룹인지 판별할 때, find를 한번 돌려 모두 경로 압축 시킬 필요가 있다.

#include <iostream>

#define MAXN 50'000
#define MAXM 100'000

using namespace std;

int n, m;
int parent[MAXN + 1]; // 1≤ 학생 번호 ≤n
int exist[MAXN + 1];
struct Edge {
	int u, v;
} edge[MAXM];

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int i) {
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]); // 경로 압축
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> edge[i].u >> edge[i].v;
	}
}

int main() {
	input();
	init();

	for (int i = 0; i < m; i++) {
		unite(edge[i].u, edge[i].v);
	}

	// exist[parent[i]] = 1 로 해서 해맸다. find를 한번 돌려 모두 경로 압축 시킬 필요가 있다.
	for (int i = 1; i <= n; i++) exist[find(i)] = 1;

	int cnt = 0;
	for (int i = 1; i <= n; i++) if (exist[i]) cnt++;
	cout << cnt;

	return 0;
}