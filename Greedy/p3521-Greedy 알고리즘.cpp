// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2861&sca=3050

/*
Greedy : ������ �ϴ� ���� �����̶�� �����Ǵ� ���� ������ ������ ������ �����ظ� ��� ���

(1) Ž������ ��������(Greedy Choice Property)
     : ���� �����̶� ������ ���� ������ ���ÿ� ������ ���� �ʴ´�.
     (���Ŀ� �����ظ� ���Ҷ� ���� ������ �����ϴ� ���� ����.
     ��, ��Ʈ��ŷ ���� ���� �� �ʿ䰡 ����� �Ѵ�.)
       

(2) ���� �κ� ����(Optimal property)
    : ū ������ �����ش� ���� ���� �κ� ������ �����ظ� �����Ѵ�.
    (���� ���� �κ� ������ �����ذ� ū ������ �����ؿ� �״�� ���ȴ�.)

� ������ �׸���� Ǯ �� �ִ°�? �� ���� �Ǻ��� ��, �� �ΰ��� ������ ��� �����ϴ��� ����.
"Ž������ ��������"�� �����غ��� "�����κ� ����"�� ������ �˾ƺ��� �����Ѵ�.
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