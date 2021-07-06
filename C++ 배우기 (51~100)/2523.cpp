#include<iostream>
using namespace std;

int main() {
	int n,j;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (j = 0; j < i + 1; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = n-1; i > 0; i--) {
		for (j = i; j > 0; j--)
			cout << '*';
		cout << '\n';
	}
	return 0;
}