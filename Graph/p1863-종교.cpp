//Union-Find
// Forest���� Tree�� ������ ���ϴ� �Ͱ� ����.
// �߿� : ���� �׷����� �Ǻ��� ��, find�� �ѹ� ���� ��� ��� ���� ��ų �ʿ䰡 �ִ�.

#include <iostream>

#define MAXN 50'000
#define MAXM 100'000

using namespace std;

int n, m;
int parent[MAXN + 1]; // 1�� �л� ��ȣ ��n
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
	return parent[i] = find(parent[i]); // ��� ����
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

	// exist[parent[i]] = 1 �� �ؼ� �ظ̴�. find�� �ѹ� ���� ��� ��� ���� ��ų �ʿ䰡 �ִ�.
	for (int i = 1; i <= n; i++) exist[find(i)] = 1;

	int cnt = 0;
	for (int i = 1; i <= n; i++) if (exist[i]) cnt++;
	cout << cnt;

	return 0;
}