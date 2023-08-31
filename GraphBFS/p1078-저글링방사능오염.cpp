/*
* 3초 후에 죽는다는 것을 일일히 다 체크할 필요가 없다.
* 마지막 결과에 +3 하면 연결된 모든 저글링은 죽어있다.
* 
* 연결되지 않아 살아남은 저글링만 체크해주면된다. O(N*N)
* 
* O(N*N + N*N) = 20000
* 
* 그런데 이 문제 메모리 제한이 64MB 이다.
* int(long) 기준 100 by 100 배열의 크기는
* 4 * 10^4 bytes = 40 KB = 0.04MB
* 충분하다.
* 
*/

/*
* - 입력의 자료형을 명확히 할 것.
* 
* MAP 이 string으로 들어오는지 , int 로 들어오는지 잘 봐야한다. 처음에 int인줄 알고 다 구현한 뒤 출력이 이상하게 나왔다.
* 이로인해 생긴 디버깅에 30분을 썼다. 처음 코드를 짜는만큼 시간이 걸렸다.
* 
* 심지어 문제에서 좌표번호가 1부터 시작하기 때문에 경계 체크에 대해 주의 해야할 점이 있었다.
* 입력을 받았을 때, y, x 를 1씩 뺐다. MAP 이 string이기 때문에 어쩔 수 없었다. 
* 이로 인해 입력보다 1작아진 y, x를 포함하도록 해야 했는데 이미 짜여진 코드를 디버깅하는데 더 오래걸렸다.
* 고친건 다음 세가지 였다.
* 
* 1. input() 에서 for (int i = 0; i < y; i++) cin >> MAP[i]; 이 아니라
*	for (int i = 0; i <= y; i++) cin >> MAP[i]; 여야 했다.
* 2. isOut() 에서 n.y >= y 이 아니라 n.y > y 여야 했다.
* 3. calc() 에서 for (int i = 0; i < y; i++) 이 아니라 for (int i = 0; i <= y; i++) 여야 했다.
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

#define MAXN 100

using namespace std;

struct Node {
	int y, x;
} start;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

int y, x;
string MAP[MAXN];
int cost[MAXN][MAXN];	// 저글링이 죽은 것이 방문처리를 하게 해준다.
int t, rest;

void input() {
	cin >> x >> y;	
	x--; y--;	// 좌표번호 1부터 시작. 여기서 경계 체크에 대해 주의 해야할 점이 생긴다.
	for (int i = 0; i <= y; i++) cin >> MAP[i];
	cin >> start.x >> start.y;
	start.x--; start.y--;
}

bool isOut(Node n) {
	return n.y < 0 || n.y > y || n.x < 0 || n.x > x;
}

void bfs() {
	queue<Node> q;
	q.push(start);
	MAP[start.y][start.x] = '0';	// 저글링 사망

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Node nxt = { now.y + dy[i], now.x + dx[i] };

			if (isOut(nxt)) continue;
			if (MAP[nxt.y][nxt.x] == '0') continue;	// 저글링 없음. 방문여부 체크 기능을 같이 하게 된다.

			MAP[nxt.y][nxt.x] = '0';	// 저글링 사망
			cost[nxt.y][nxt.x] = cost[now.y][now.x] + 1;
			q.push(nxt);
		}
	}
}

void calc() {
	for (int i = 0; i <= y; i++) {
		for (int j = 0; j <= x; j++) {
			if (MAP[i][j] == '1') rest++;
			if (cost[i][j] != 0) t = max(t, cost[i][j]);
		}
	}
}

int main() {
	input();
	bfs();
	calc();
	cout << t + 3 << endl << rest;	// 3초 후 저글링 이 죽음을 한번에 처리

	return 0;
}