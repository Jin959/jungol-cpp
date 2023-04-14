// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2861&sca=3050

/*
Greedy : 결정을 하는 순간 최적이라고 생각되는 것을 선택해 나가는 것으로 최종해를 얻는 방법

(1) 탐욕적인 선택조건(Greedy Choice Property)
     : 현재 최적이라 선택한 것이 이후의 선택에 영향을 주지 않는다.
     (이후에 최적해를 구할때 현재 선택을 번복하는 일이 없다.
     즉, 백트래킹 같은 것을 할 필요가 없어야 한다.)
       

(2) 최적 부분 구조(Optimal property)
    : 큰 문제의 최적해는 보다 작은 부분 문제의 최적해를 포함한다.
    (보다 작은 부분 문제의 최적해가 큰 문제의 최적해에 그대로 사용된다.)

어떤 문제가 그리디로 풀 수 있는가? 에 대해 판별할 때, 위 두가지 조건을 모두 만족하는지 본다.
"탐욕적인 선택조건"을 적용해보고 "최적부분 구조"를 갖는지 알아보며 설계한다.
*/

#include <iostream>

#define PEND_TYPE 5

using namespace std;

int weight[PEND_TYPE] = { 1, 2, 4, 8, 16 };
int pend_n[PEND_TYPE];
int cnt, n;

void init() {
    int w;
    // a, b, c, d, e;
    for (int i = 0; i < PEND_TYPE; i++) {
        cin >> pend_n[i];
    }
    cin >> n;
}

void cal() {    
    for (int i = PEND_TYPE - 1; i >= 0; i--) {
        int now_cnt = n / weight[i];

        if (pend_n[i] == 0) continue;
        else if (pend_n[i] < now_cnt) {
            now_cnt = pend_n[i];
        }

        cnt += now_cnt;
        pend_n[i] -= now_cnt;

        n -= weight[i] * now_cnt;
    }
}

int main() {
    init();
    cal();

    if (n) {
        cout << "impossible";
    }
    else {
        cout << cnt;
    }

    return 0;
}