#pragma warning(disable:4996);
#include <iostream>
using namespace std;

int N;
int arr[65][65];

bool isAllEqual(int y1, int y2, int x1, int x2) {
    int bound = arr[y1][x1];
    for (int y = y1; y <= y2; y++)
        for (int x = x1; x <= x2; x++)
            if (bound != arr[y][x])
                return false;
    return true;
}

void f(int y1, int y2, int x1, int x2) {
    if (isAllEqual(y1, y2, x1, x2)) {
        cout << arr[y1][x1];
        return;
    }
    else {
        cout << "(";
        int length = (x2 - x1 + 1) / 2;
        f(y1, y1 + length - 1, x1, x1 + length - 1); // 1사분면
        f(y1, y1 + length - 1, x1 + length, x2);     // 2사분면
        f(y1 + length, y2, x1, x1 + length - 1);     // 3사분면
        f(y1 + length, y2, x1 + length, x2);     // 4사분면
        cout << ")";
    }
}

int main() {
    cin >> N;
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= N; x++)
            scanf("%1d", &arr[y][x]);

    f(1, N, 1, N);
}