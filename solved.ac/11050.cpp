#include<iostream>
using namespace std;

int f(int n) {
	if (n <= 1)
		return 1;
	else
		return n * f(n - 1);
}

int main() {
	int n, k, fac;
	cin >> n >> k;
	fac = f(n) / ( f(k)*(f(n - k)) );
	cout << fac;
}