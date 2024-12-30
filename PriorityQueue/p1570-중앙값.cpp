#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAXN 20'000

vector<int> medians;
int mid;
priority_queue<int, vector<int>, greater<int>> minheap;
priority_queue<int> maxheap;

void print() {
	for (int i = 0; i < medians.size(); i++) {
		cout << medians[i] << endl;
	}
}

void push(int value) {
	if (value > mid) {
		minheap.push(value);
	} else {
		maxheap.push(value);
	}
}
// push 함수를 다음과 같이 설계해서 value == mid 인 경우를 세지 못해서 틀렸었다.
/*if (value > mid) {
	minheap.push(value);
}
if (value < mid) {
	maxheap.push(value);
}*/

int main() {

	int n;	
	cin >> n >> mid;
	medians.push_back(mid); // 처음 1개 뽑는 거

	// 2개 씩 뽑는 거
	for (int i = 0; i < n / 2; i++) {

		int a, b;
		cin >> a >> b;
		push(a);
		push(b);

		if (minheap.size() > maxheap.size()) {
			maxheap.push(mid);
			mid = minheap.top();
			minheap.pop();
		}
		if (minheap.size() < maxheap.size()) {
			minheap.push(mid);
			mid = maxheap.top();
			maxheap.pop();
		}

		medians.push_back(mid);
	}

	print();

	return 0;
}