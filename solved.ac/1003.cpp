#include<iostream>
using namespace std;

int zero[41] = { 0 }, one[41] = { 0 };

int fz(int n) {
	if (n == 1)
		return 0;
	if (zero[n] != 0)
		return zero[n];
	else {
		zero[n] = fz(n - 1) + fz(n - 2);
		return zero[n];
	}
}
int fo(int n) {
	if (n == 0)
		return 0;
	if (one[n] != 0)
		return one[n];
	else {
		one[n] = fo(n - 1) + fo(n - 2);
		return one[n];
	}
}


int main() {
	zero[0] = 1, one[1] = 1;
	int t,n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fz(n) << ' ' << fo(n) << '\n';
	}
}