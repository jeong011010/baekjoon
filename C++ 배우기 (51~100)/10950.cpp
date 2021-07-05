#include<iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n;
	int* tmp = new int[n]();
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		tmp[i] = a + b;
	}
	for (int i = 0; i < n; i++)
		cout << tmp[i]<<'\n';
	return 0;
}