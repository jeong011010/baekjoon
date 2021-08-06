#include<iostream>
#include<cmath>
using namespace std;

int n, r, c, sum;

void f(int y, int x, int s) {
	if (y == r && x == c) {
		cout << sum << '\n';
		return;
	}
	if (r < y + s && r >= y && c < x + s && c >= x) {
		f(y, x, s / 2);
		f(y, x + s / 2, s / 2);
		f(y + s / 2, x, s / 2);
		f(y + s / 2, x + s / 2, s / 2);
	}
	else {
		sum += s * s;
	}
}

int main() {
	cin >> n >> r >> c;
	f(0, 0, pow(2,n));
}