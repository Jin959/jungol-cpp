// https://www.jungol.co.kr/problem/1855

/*
* 모이는 곳을 시작점으로 한다.
* 모든 노드에 대해 다익스트라를 돌리고 돌릴때 마다 학생들의 위치까지의 합을 구한다. 
* 루프를 돌때마다 그합의 최소를 갱신해간다.
* 
* 다익스트라를 한 번 수행하면 출발지인 한 점에서 다른 모든 점으로의 최소비용을 기록하게 된다.
* 따라서 아래와 같은 시간 복잡도 계산은 틀렸다.
* 
* PN * ElogV -> PN * ClogP = 800 * 500 * 1450 * log(800)
* ~ 800 * 500 * 1500 * log(1024) = 6e9 > 1e8
* 
* 다시 계산하면, 한 번의 탐색에 다른 모든 노드의 기록을 수행하므로
* P * ElogV -> P * ClogP = 800 * 1450 * log(800)
* 
* 학생들의 비용을 합하는 것은 탐색종료 후 getSumGoalAcc함수에서 dat로 구하므로 학생수 N 만큼 상수 시간만 든다.
* 따라서, 시간 복잡도는 최고차항만 다루기 때문에 계산에서 제외하면 된다.
*/

// cost <= 255 로, 최악의 경우 acc=255 값으로 모든 간선을 거쳤을때 255 * 1450 ~ 300 * 1500 = 450'000 -> Node.cost 는 int 가능
// 그러나 모든 학생들의 최소경로 합은 450'000 * 500 = 225e6 = 2.25e8 -> int 초과할 가능성이 조금있다.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define MAXN 500	// 학생수
#define MAXP 800	// 노드수
#define MAXC 1450	// 간선수
#define INF 21e8

using namespace std;

struct Node {	// heap 에 사용
	int node, acc;

	bool operator< (Node another) const {
		return this->acc > another.acc;
	}
};

struct Edge {	// adj 에 사용
	int to, cost;
};

int n, p, c;
bool visited[MAXP + 1];	// 노드 번호 1부터
int dist[MAXP + 1];
int student[MAXN];	// 학생들 위치
vector<Edge> adj[MAXP + 1];

void input() {
	cin >> n >> p >> c;

	int u, v, cost;
	// 양방향, 노드 번호 1부터
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
	//memset(dist, '?', sizeof(dist));	// 문자 '?'를 넣으면 10억이 저장된다.
	memset(dist, 'z', sizeof(dist));	// 문자 'z'를 넣으면 20억이 저장된다.
}

void dijkstra(Node start) {
	priority_queue<Node> pq;
	pq.push(start);

	dist[start.node] = 0;	// 잊지 말기

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