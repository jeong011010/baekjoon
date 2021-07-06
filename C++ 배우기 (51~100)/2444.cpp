#include<iostream>
using namespace std;

int main() {
	int n,j;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (j = i+1; j < n; j++)
			cout << ' ';
		for (j = 1; j < (i+1) * 2; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = n-1; i > 0; i--) {
		for (j = n; j > i; j--)
			cout << ' ';
		for (j = i * 2; j > 1; j--)
			cout << '*';
		cout << '\n';
	}
	return 0;
}