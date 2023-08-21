// https://www.jungol.co.kr/problem/1855

/*
* ���̴� ���� ���������� �Ѵ�.
* ��� ��忡 ���� ���ͽ�Ʈ�� ������ ������ ���� �л����� ��ġ������ ���� ���Ѵ�. 
* ������ �������� ������ �ּҸ� �����ذ���.
* 
* ���ͽ�Ʈ�� �� �� �����ϸ� ������� �� ������ �ٸ� ��� �������� �ּҺ���� ����ϰ� �ȴ�.
* ���� �Ʒ��� ���� �ð� ���⵵ ����� Ʋ�ȴ�.
* 
* PN * ElogV -> PN * ClogP = 800 * 500 * 1450 * log(800)
* ~ 800 * 500 * 1500 * log(1024) = 6e9 > 1e8
* 
* �ٽ� ����ϸ�, �� ���� Ž���� �ٸ� ��� ����� ����� �����ϹǷ�
* P * ElogV -> P * ClogP = 800 * 1450 * log(800)
* 
* �л����� ����� ���ϴ� ���� Ž������ �� getSumGoalAcc�Լ����� dat�� ���ϹǷ� �л��� N ��ŭ ��� �ð��� ���.
* ����, �ð� ���⵵�� �ְ����׸� �ٷ�� ������ ��꿡�� �����ϸ� �ȴ�.
*/

// cost <= 255 ��, �־��� ��� acc=255 ������ ��� ������ �������� 255 * 1450 ~ 300 * 1500 = 450'000 -> Node.cost �� int ����
// �׷��� ��� �л����� �ּҰ�� ���� 450'000 * 500 = 225e6 = 2.25e8 -> int �ʰ��� ���ɼ��� �����ִ�.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define MAXN 500	// �л���
#define MAXP 800	// ����
#define MAXC 1450	// ������
#define INF 21e8

using namespace std;

struct Node {	// heap �� ���
	int node, acc;

	bool operator< (Node another) const {
		return this->acc > another.acc;
	}
};

struct Edge {	// adj �� ���
	int to, cost;
};

int n, p, c;
bool visited[MAXP + 1];	// ��� ��ȣ 1����
int dist[MAXP + 1];
int student[MAXN];	// �л��� ��ġ
vector<Edge> adj[MAXP + 1];

void input() {
	cin >> n >> p >> c;

	int u, v, cost;
	// �����, ��� ��ȣ 1����
	for (int i = 0; i < c; i++) {
		cin >> u >> v >> cost;
		adj[u].push_back({ v, cost });
		adj[v].push_back({ u, cost });
	}

	for (int i = 0; i < n; i++) cin >> student[i];
}

void init() {
	memset(visited, false, sizeof(visited));
	//fill(dist, dist + (MAXP + 1), INF);
	//memset(dist, '?', sizeof(dist));	// ���� '?'�� ������ 10���� ����ȴ�.
	memset(dist, 'z', sizeof(dist));	// ���� 'z'�� ������ 20���� ����ȴ�.
}

void dijkstra(Node start) {
	priority_queue<Node> pq;
	pq.push(start);

	dist[start.node] = 0;	// ���� ����

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (visited[now.node]) continue;
		visited[now.node] = true;

		for (Edge nxt : adj[now.node]) {
			if (now.acc + nxt.cost < dist[nxt.to]) {
				dist[nxt.to] = now.acc + nxt.cost;
				pq.push({ nxt.to, dist[nxt.to] });
			}
		}
	}
}

long long getSumStudentAcc() {
	long long sum = 0;
	for (int i = 0; i < n; i++) sum += dist[student[i]];

	return sum;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	input();

	long long sum = 9e18;
	for (int i = 1; i <= p; i++) {
		init();
		dijkstra({ i, 0 });
		sum = min(sum, getSumStudentAcc());
	}

	cout << sum;

	return 0;
}