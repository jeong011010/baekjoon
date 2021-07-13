#include <iostream>
#include <queue>
using namespace std;

// global
priority_queue<int, vector<int>, greater<int> > pq;
int n;

int main() {
    cin >> n;
    for (int n_idx = 0; n_idx < n; n_idx++) {
        int _input_int;
        cin >> _input_int;

        // 0�̸� �ϳ� ���� ���
        // �ƴϸ� ���� 
        switch (_input_int) {
        case 0:
            if (pq.size()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << "0\n";
            }
            break;
        default:
            pq.push(_input_int);
            break;
        }
    }

    return 0;
}
